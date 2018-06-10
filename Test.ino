#include <Servo.h> 
// コメント、コメント以外の場所に全角の文字が入らないように注意。特に空白。
/* これもコメント */
const int buttonPin = 2;     // ボタン番号
int buttonState = 0;         // ボタン状態
const int ledPin = 13;       // LED番号
Servo myservo;               // サーボモーターを使用
const int servoPin = 4;      // サーボピン番号
const int dcMotorPin0 = 9;   // DCモーターの端子番号その１
const int dcMotorPin1 = 10;  // DCモーターの端子番号その２

void setup()  { 
  // LEDピンを出力として初期化
  pinMode(ledPin, OUTPUT);

  // ボタンを入力として初期化
  pinMode(buttonPin, INPUT_PULLUP);

  // サーボモーターとサーボピンを関連付ける
  myservo.attach(servoPin);
  // サーボモータの初期角度を0度にする
  myservo.write(0);

  // DCモーターピンを出力として初期化
  pinMode(dcMotorPin0, OUTPUT);
  pinMode(dcMotorPin1, OUTPUT);
  // DCモーターを停止（両方に同じ値を入れると停止）
  analogWrite(dcMotorPin0, 0);
  analogWrite(dcMotorPin1, 0);
}

void loop()  { 
  // ボタン状態を読み込む
  while(digitalRead(buttonPin)){
    // ボタンが押されたらループから出る
    if (buttonState == HIGH) {     
      break; 
    } 
  }

  // LEDの明るさを0から255まで5ずつ増やす
  for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) { 
    // アナログ値としてLEDの明るさをセットする
    analogWrite(ledPin, fadeValue);         
    // 30ミリ秒待つ
    delay(30);                            
  } 

  // LEDの明るさを255から0まで5ずつ減らす
  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) { 
    // アナログ値としてLEDの明るさをセットする
    analogWrite(ledPin, fadeValue);         
    // 30ミリ秒待つ
    delay(30);                            
  } 

  // Move servo motor
  myservo.write(90);   // サーボモーターを90度にする
  delay(2000);         // 2秒待つ
  myservo.write(180);  // サーボモーターを180度にする
  delay(2000);         // 2秒待つ
  myservo.write(0);    // サーボモーターを0度にする
  delay(2000);         // 2秒待つ

  // DCモーターを3秒間動かす
  analogWrite(dcMotorPin0, 150);
  delay(3000);
  // DCモーターを止める
  analogWrite(dcMotorPin0, 0);
}


