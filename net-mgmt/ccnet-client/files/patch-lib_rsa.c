--- lib/rsa.c.orig	2017-02-25 08:37:57 UTC
+++ lib/rsa.c
@@ -13,7 +13,7 @@
 
 /* Forward compatibility functions if libssl < 1.1.0. */
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 
 int RSA_set0_key(RSA *r, BIGNUM *n, BIGNUM *e, BIGNUM *d)
 {
