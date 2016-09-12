--- src/common.h.orig	2016-06-27 07:29:32 UTC
+++ src/common.h
@@ -448,7 +448,7 @@ extern char *sys_errlist[];
 #define OPENSSL_NO_TLS1_2
 #endif /* OpenSSL older than 1.0.1 || defined(OPENSSL_NO_TLS1) */
 
-#if OPENSSL_VERSION_NUMBER>=0x10100000L
+#if OPENSSL_VERSION_NUMBER>=0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
 #ifndef OPENSSL_NO_SSL2
 #define OPENSSL_NO_SSL2
 #endif /* !defined(OPENSSL_NO_SSL2) */
@@ -474,7 +474,7 @@ extern char *sys_errlist[];
 #include <openssl/des.h>
 #ifndef OPENSSL_NO_DH
 #include <openssl/dh.h>
-#if OPENSSL_VERSION_NUMBER<0x10100000L
+#if OPENSSL_VERSION_NUMBER<0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 int DH_set0_pqg(DH *dh, BIGNUM *p, BIGNUM *q, BIGNUM *g);
 #endif /* OpenSSL older than 1.1.0 */
 #endif /* !defined(OPENSSL_NO_DH) */
