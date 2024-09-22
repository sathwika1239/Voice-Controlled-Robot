#include<SoftwareSerial.h>
SoftwareSerial bt(11,10);
String readvoice;
void setup() {
  // put your setup code here, to run once:
bt.begin(9600);
Serial.begin(9600);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
while(bt.available()){
  delay(10);
  char c=bt.read();
  readvoice +=c;
}
if(readvoice.length()>0){
  Serial.println(readvoice);
  if(readvoice=="*forward#"){
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    delay(100);
  }
    else if(readvoice=="*backward#"){
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    delay(100);
  }
      else if(readvoice=="*left#"){
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    delay(100);
  }
        else if(readvoice=="*right#"){
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    delay(100);
  }
          else if(readvoice=="*stop#"){
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    delay(100);
  }
  
  readvoice="";
}
}
