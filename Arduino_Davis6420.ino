/* utilzei como base o documento disponivel em https://www.davisinstruments.com/product_documents/weather/spec_sheets/6420_SS.pdf
 *  para ligação dos fios.
 *  Amarelo  ----> 3VDC (utilizei 3.3 do proprio arduino )
 *  Vermelho ----> GND
 *  Verde    ----> Saida de dados  ( conectado na porta Ao )
 *  
 */
 float folha;
 int folha1;

void setup() {
  Serial.begin(9600);
}
void loop() {
  // faz a leitura analogical do pino 0:
  int sensorValue = analogRead(A0);
  // Converte a leitura analógica (que vai de 0 - 1023) para um valor de tensão (0 - 5V):
  float voltage = sensorValue * (5 / 1023.0);
  if (voltage >= 3.10) {
    folha = 0;
  }
  if (voltage <= 2.62) {
    folha = 100;
  }
  if ((voltage <= 3.09) &&  (voltage >= 2.63)) {
    Serial.println("calcular %");
    float voltage_final = 3.10 - voltage;
    //folha = voltage_final * 200; // imprime os dados em % 
    folha1 = voltage_final * 30;// imprime os dados de 0 a 15 conforme dataasheet davis
}


// escreve o valor de tensão via comunicação serial:

Serial.print(folha1);
Serial.println(" % molhado");
Serial.println(voltage);


// condições  medida, valor seco (voltage>=3.1 e 100% molhado para (voltage=2.60) para multiplicação
//
delay(54000); //intervalo de mediçao recomendado a cada 54 segundos

}
