--- ./prettypacket.h.orig	2012-12-04 10:31:27.000000000 +0100
+++ ./prettypacket.h	2014-03-06 14:57:20.000000000 +0100
@@ -102,7 +102,7 @@
  * @param counter protocol number offset
  * @return protocol number in host format
  */
-inline uint8_t protocol_8bit_extract(const char *packet_buffer, int counter) {
+uint8_t protocol_8bit_extract(const char *packet_buffer, int counter) {
     return *(packet_buffer + counter);
 }
 
@@ -113,7 +113,7 @@
  * @param counter protocol number offset
  * @return protocol number in host format
  */
-inline uint16_t protocol_16bit_extract(const char *packet_buffer, int counter) {
+uint16_t protocol_16bit_extract(const char *packet_buffer, int counter) {
     return ntohs(*((uint16_t *)(packet_buffer + counter)));
 }
 
@@ -123,7 +123,7 @@
  * @param counter protocol number offset
  * @return protocol number in host format
  */
-inline uint64_t protocol_48bit_extract(const char *packet_buffer, int counter) {
+uint64_t protocol_48bit_extract(const char *packet_buffer, int counter) {
     uint64_t value = 0;
 
     int i;
@@ -144,7 +144,7 @@
  * @param counter read bytes counter
  * @param field_text description of the field
  */
-inline field_print (const char *packet_buffer, int field_size, int *counter, const char *field_text) {
+void field_print (const char *packet_buffer, int field_size, int *counter, const char *field_text) {
     
     char *tmp_hexstr = raw_to_hexstr(packet_buffer + *counter, field_size);
     *counter += field_size;
