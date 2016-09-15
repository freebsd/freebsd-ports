--- src/ssl.c.orig	2016-06-02 13:43:49 UTC
+++ src/ssl.c
@@ -78,7 +78,7 @@ int ssl_init(void) { /* init SSL before 
 }
 
 #ifndef OPENSSL_NO_DH
-#if OPENSSL_VERSION_NUMBER<0x10100000L
+#if OPENSSL_VERSION_NUMBER<0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 /* this is needed for dhparam.c generated with OpenSSL >= 1.1.0
  * to be linked against the older versions */
 int DH_set0_pqg(DH *dh, BIGNUM *p, BIGNUM *q, BIGNUM *g) {
