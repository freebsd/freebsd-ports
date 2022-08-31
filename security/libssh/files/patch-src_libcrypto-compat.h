--- src/libcrypto-compat.h.orig	2022-07-07 13:53:51 UTC
+++ src/libcrypto-compat.h
@@ -7,7 +7,7 @@
 #define NISTP384 "P-384"
 #define NISTP521 "P-521"
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || (defined(LIBRESSL_VERSION_NUMBER) && OPENSSL_VERSION_NUMBER < 0x20700000L)
 
 #include <openssl/rsa.h>
 #include <openssl/dsa.h>
