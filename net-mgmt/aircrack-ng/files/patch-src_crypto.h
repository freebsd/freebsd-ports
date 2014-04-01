--- src/crypto.h.orig	2014-04-01 19:15:06.228646731 +0200
+++ src/crypto.h	2014-04-01 19:16:22.960640528 +0200
@@ -35,6 +35,7 @@
 #ifndef _CRYPTO_H
 #define _CRYPTO_H
 
+#include <sys/types.h>
 #ifndef uint8
 #define uint8  unsigned char
 #endif
