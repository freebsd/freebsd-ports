--- crypto.h.orig	Fri Feb 21 10:11:51 2003
+++ crypto.h	Fri Feb 21 10:11:58 2003
@@ -49,7 +49,8 @@
 
 #else
 
-#include <des.h>
+#define OPENSSL_DES_LIBDES_COMPATIBILITY
+#include <openssl/des.h>
 #ifdef USE_BLOWFISH
 #include <blf.h>
 #endif
