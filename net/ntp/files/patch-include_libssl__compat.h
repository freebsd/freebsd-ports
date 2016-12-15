--- include/libssl_compat.h.orig	2016-11-21 12:28:40 UTC
+++ include/libssl_compat.h
@@ -25,7 +25,7 @@
 #include "openssl/rsa.h"
 
 /* ----------------------------------------------------------------- */
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 /* ----------------------------------------------------------------- */
 
 # include <openssl/objects.h>
