--- md5.c.orig	2018-04-13 14:15:16.302782000 +0300
+++ md5.c	2018-04-13 14:25:07.662155000 +0300
@@ -17,7 +17,7 @@
  */
 
 #include <string.h>
-#include <byteswap.h>
+#include <sys/endian.h>
 #include "md5.h"
 
 #ifndef HIGHFIRST
@@ -25,7 +25,7 @@
 #else
 static void byteReverse(unsigned char *buf, unsigned longs) {
 	for (; longs; --longs, buf +=4)
-		*((uint32_t *) buf) = bswap_32(*((uint32_t *) buf));
+		*((uint32_t *) buf) = bswap32(*((uint32_t *) buf));
 }
 #endif
 
