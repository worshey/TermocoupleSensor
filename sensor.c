#include <TFT.h>  
#include <SPI.h>

#define sc   4
#define dc   5
#define rst  6

TFT TFTscreen = TFT(sc, dc, rst);

#include "max6675.h" //INCLUSÃO DE BIBLIOTECA

int ktcSO = 8; //PINO DIGITAL (SO)
int ktcCS = 9; //PINO DIGITAL (CS)
int ktcCLK = 10; //PINO DIGITAL (CLK / SCK)
int pinBuzzer = 2;

MAX6675 ktc(ktcCLK, ktcCS, ktcSO); //CRIA UMA INSTÂNCIA UTILIZANDO OS PINOS (CLK, CS, SO)
  
void setup(){
  TFTscreen.begin();
  TFTscreen.background(0, 0, 0);
  TFTscreen.setTextSize(2);
  delay(1500); 
}

void loop(){
   //generate a random color
  int redRandom = random(0, 255);
  int greenRandom = random (0, 255);
  int blueRandom = random (0, 255);

  TFTscreen.stroke(redRandom, greenRandom, blueRandom);
  TFTscreen.background(0,0,0); //clear the background before set a new value

  long temp_as_long = int(ktc.readCelsius());
  
  switch (temp_as_long) {
    case 0 ... 40:
      TFTscreen.stroke(255,255,255); //color: white
      break;
    case 41 ... 60:
      TFTscreen.stroke(0,204,0); //color: green
      break;
    case 61 ... 80:
      TFTscreen.stroke(0,204,204); //color: yellow
      pinMode(pinBuzzer,HIGH);
      tone(pinBuzzer,2500);   
      delay(250);
      tone(pinBuzzer,3500);  
      delay(250);  
      pinMode(pinBuzzer,LOW);
      break;
    case 81 ... 100:
      TFTscreen.stroke(255,0,127); //color: purple
      pinMode(pinBuzzer,HIGH);
      tone(pinBuzzer,2500);   
      delay(200);
      tone(pinBuzzer,3500);  
      delay(200);  
      tone(pinBuzzer,2500);  
      delay(200);  
      tone(pinBuzzer,3500);  
      delay(200);  
      tone(pinBuzzer,2500); 
      delay(200);  
      tone(pinBuzzer,3500); 
      delay(200); 
        tone(pinBuzzer,2500); 
      delay(200); 
      tone(pinBuzzer,3500); 
      delay(200); 
      pinMode(pinBuzzer,LOW);
      break;
   }

  TFTscreen.print(ktc.readCelsius());
  TFTscreen.println(" C"); 
  TFTscreen.setCursor(45,10);  
  TFTscreen.rect(45,50,85,45);
  TFTscreen.rect(10,55,35,35);
  TFTscreen.circle(10,46,3);
  delay(5000);
}
