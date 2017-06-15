--- amfm.c.orig	2017-02-27 12:28:56 UTC
+++ amfm.c
@@ -12,6 +12,7 @@
 
 #include <stdio.h>
 #include <string.h>
+#include <stdlib.h>
 #include <unistd.h>
 #include <hid.h>
 
@@ -28,7 +29,7 @@ int main(int argc, const char** argv) {
   HIDInterface* hid;
   HIDInterfaceMatcher matcher = { RADIO_VENDID, RADIO_DEVID, NULL, NULL, 0 };
 
-  unsigned char PACKET[SEND_PACKET_LENGTH] = { 0x28, 0xe2, 0x06, 0x03, 0x29, 0x52, 0x00, 0x10 };
+  unsigned char PACKET[SEND_PACKET_LENGTH] = { 0x28, 0xe2, 0x06, 0x03, 0x29, 0xd2, 0x00, 0x10 };
   unsigned char ZERO[0];
   unsigned short encodedFreq;
   unsigned int freq;
