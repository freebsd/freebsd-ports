--- src/trspi/crypto/openssl/rsa.c.orig	2016-11-23 12:26:19 UTC
+++ src/trspi/crypto/openssl/rsa.c
@@ -38,7 +38,7 @@
 #define DEBUG_print_openssl_errors()
 #endif
 
-#if OPENSSL_VERSION_NUMBER < 0x10100001L
+#if OPENSSL_VERSION_NUMBER < 0x10100001L || (defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000L)
 static int
 RSA_set0_key(RSA *r, BIGNUM *n, BIGNUM *e, BIGNUM *d)
 {
