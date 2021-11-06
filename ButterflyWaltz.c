#include <avr/io.h>
#include <avr/interrupt.h>
#define A 0x80
#define B 0xC0
#define C 0xE0
#define D 0xF0
#define E 0xF8
#define F 0xFC
#define G 0xFE
#define H 0xFF
volatile signed char counter; 
	float right[] = {
					880,880, 932.3275, //1
					1046.502,1046.502,1046.502,1046.502, 698.4565, 659.2551, //
					698.4565,698.4565,698.4565,698.4565, 1046.502,1046.502, //
					1046.502, 1046.502, 1174.659, 932.3275, 880,//
					932.3275,932.3275,932.3275,932.3275, 880, 932.3275,//5
					1046.502,1046.502,1046.502,1046.502, 698.4565, 659.2551,//
					698.4565,698.4565,698.4565,698.4565, 880,880,//
					587.3295,587.3295,587.3295,587.3295,587.3295,//
					659.2551,659.2551,659.2551,659.2551, 880, 932.3275,//
					1046.502,1046.502,1046.502,1046.502, 698.4565, 659.2551,//10
					698.4565,698.4565,698.4565,698.4565, 1046.502, 1046.502,//
					1046.502, 1046.502,1046.502, 1108.731, 932.3275, 880,//
					932.3275,932.3275,932.3275,932.3275, 880, 932.3275,//
					1046.502,1046.502,1046.502, 1396.913, 1318.510, 1396.913,//
					1046.502,1046.502,1046.502, 1396.913, 1318.510, 1396.913,//15
					1046.502,1046.502,1046.502,1046.502,1046.502,//
					1108.731,1108.731,1108.731,1108.731, 1108.731, 1318.510,//
					1396.913,1396.913,1396.913, 1318.510, 1567.982, 1318.510,//
					1396.913,1396.913,1396.913, 1318.510, 1396.913, 1318.510,//
					1396.913,1396.913, 1318.510,1318.510, 1174.659,1174.659,//20
					783.9909,783.9909,783.9909, 783.9909, 880, 783.9909,//
					698.4565,698.4565,698.4565, 783.9909, 880, 1174.659,//
					1046.502,1046.502, 880, 880, 698.4565, 880,//
					783.9909,783.9909,783.9909,783.9909,783.9909,//
					783.9909, 698.4565, 659.2551,//25
					698.4565,698.4565,698.4565,698.4565,698.4565,//
					587.3295,587.3295,587.3295, 493.8833, 783.9909, 698.4565,//
					659.2551,659.2551, 698.4565, 698.4565, 783.9909, 783.9909,//
					523.2511,523.2511,523.2511,523.2511,0};

	int led[] = {B,B,C,
				D,D,D,D,C,B,
				C,C,C,C,D,D,
				E,E,F,D,C,
				D,D,D,D,C,D,
				E,E,E,E,C,B,
				C,C,C,C,D,D,
				A,A,A,A,A,
				B,B,B,B,C,D,
				E,E,E,E,C,B,
				C,C,C,C,F,F,
				F,F,F,G,D,C,D,D,D,D,C,D,E,E,E,F,E,F,
                E,E,E,F,E,F,    
                E,E,E,E,E,
                F,F,F,F,F,G,
                H,H,H,G,H,G,
				H,H,H,G,H,G,
                H,H,G,G,F,F,    
                D,D,D,D,E,D,
                C,C,C,D,E,F,
                E,E,D,D,C,D,
                C,C,C,C,C,
				C,B,A,          
                B,B,B,B,B,
                A,A,A,0x00,C,B,
                A,A,B,B,C,C,
                A,A,A,A,};

	unsigned char Num[10]= {0x3F,0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x67};
	 
	
				

char seg[]={0x08,0x04,0x02,0x01};
int main()
{


	int n;
	EICRA = 0x00;   //인터 4, 5만 사용 ,스위치 사용을 목적
	EICRB = 0x0A;  //
	EIMSK = 0x30; 
	sei();
	DDRC = 0xFF; 
	DDRG = 0x0F;
	DDRA = 0xFF;
	DDRB |= (1<<DDB4); //OC0핀 출력
	TCCR0 = 0x1E;	// 타이머0 CTC모드, 분주
	TCCR1A = 0x00;	// 노멀모드 동작
	TCCR1B = 0x04;	// 타이머1 분주
	
	TCNT0 = 0;
	TCNT1 = 65536 - 15625;
	counter = 0;
	while(1){
			for(int i=0; i<=500; ++i)
				{
					
				    PORTC = 0x53;
			    	PORTG = 0x01;
				}
			for(int i=0; i<=500; ++i)
				{
					PORTC = 0x80;
					PORTG = 0x02;
					}
			for(int i=0; i<=500; ++i)
				{
					PORTC = 0x5C;
					PORTG = 0x04;
				}
				for(int i=0; i<=500; ++i)
				{
					
				    PORTC = 0x6F;
			    	PORTG = 0x08;
				}		
	if(counter >1 )
	break;
	}
	counter =1;

	for(n=0; right[n]!=0; n++){

	if(counter <= 0){
		while(1){
		OCR0 = 0x00;
		if(counter>0)
		break;
			}
		}
		OCR0 = (int)(16000000/(right[n]*256*2));
	
				 	PORTC = 0x40;
			    	PORTG = seg[n%4];
		while((TIFR & 0x04) == 0) // 타이머1 오버플로우 발생
		;
		PORTA = led[n];
		TIFR |= 0x04;
		TCNT1 = 65536 - 15625;
		}
		PORTA = 0x00;
		PORTC = 0x40;
		PORTG = 0x0f;
		
		TCCR0 = 0;
			while(1)
			{	
			for(int i=0; i<=500; ++i)
				{
					
				    PORTC = 0x5E;
			    	PORTG = 0x01;
				}
			for(int i=0; i<=500; ++i)
				{
					PORTC = 0x54;
					PORTG = 0x02;
					}
			for(int i=0; i<=500; ++i)
				{
					PORTC = 0x79;
					PORTG = 0x04;
				}		
			}	
}

ISR(INT4_vect)
	{
		counter = 2;
	}

ISR(INT5_vect)
	{
		counter = 0;
	}


