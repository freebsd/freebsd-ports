--- trackdb/lec.cc.orig	Sun Nov 24 16:28:30 2002
+++ trackdb/lec.cc	Sun Feb 15 03:54:23 2004
@@ -278,7 +278,7 @@
   u_int32_t crc = 0;
 
   while (len--) {
-    crc = CRCTABLE[(crc ^ *data++) & 0xffL] ^ (crc >> 8);
+    crc = CRCTABLE[(crc ^ *data++) & 0xff] ^ (crc >> 8);
   }
 
   return crc;
