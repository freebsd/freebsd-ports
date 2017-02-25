--- src/utils/CryptoKey.cpp.orig	2016-11-04 22:05:33 UTC
+++ src/utils/CryptoKey.cpp
@@ -39,7 +39,7 @@
 #include <openssl/bio.h>
 #include <openssl/pem.h>
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 void RSA_get0_factors(const RSA *r, const BIGNUM **p, const BIGNUM **q)
 {
   *p = r->p;
