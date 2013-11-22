--- ./md5.c.orig	2012-10-09 13:34:42.000000000 +0300
+++ ./md5.c	2012-10-09 13:34:51.000000000 +0300
@@ -20,13 +20,13 @@
  */
 
 #include <string.h>
-#include <endian.h>
+#include <sys/endian.h>
 #include "md5.h"
 
 void MD5_Transform(uint32 *buf, uint32 const *in);
 
-#define IS_BIG_ENDIAN() (__BYTE_ORDER == __BIG_ENDIAN)
-#define IS_LITTLE_ENDIAN() (__BYTE_ORDER == __LITTLE_ENDIAN)
+#define IS_BIG_ENDIAN() (_BYTE_ORDER == _BIG_ENDIAN)
+#define IS_LITTLE_ENDIAN() (_BYTE_ORDER == _LITTLE_ENDIAN)
 
 static void byteReverse(unsigned char *buf, unsigned longs);
 
