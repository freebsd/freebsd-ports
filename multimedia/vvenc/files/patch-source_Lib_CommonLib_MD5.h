--- source/Lib/CommonLib/MD5.h.orig	2023-03-07 19:25:15 UTC
+++ source/Lib/CommonLib/MD5.h
@@ -57,11 +57,11 @@ static const uint32_t MD5_DIGEST_STRING_LENGTH=16;
 #ifndef __BIG_ENDIAN__
 # define byteReverse(buf, len)    /* Nothing */
 #else
-void byteReverse(uint32_t *buf, unsigned len);
+static void byteReverse(uint32_t *buf, unsigned len);
 /*
  * Note: this code is harmless on little-endian machines.
  */
-void byteReverse(uint32_t *buf, unsigned len)
+static void byteReverse(uint32_t *buf, unsigned len)
 {
   uint32_t t;
   do {
