--- src/lib/crypt_ops/compat_openssl.h.orig	2022-10-17 12:38:04 UTC
+++ src/lib/crypt_ops/compat_openssl.h
@@ -25,14 +25,13 @@
 #error "We require OpenSSL >= 1.0.1"
 #endif
 
-#if OPENSSL_VERSION_NUMBER >= OPENSSL_V_SERIES(1,1,0) && \
-   ! defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER >= OPENSSL_V_SERIES(1,1,0)
 /* We define this macro if we're trying to build with the majorly refactored
  * API in OpenSSL 1.1 */
 #define OPENSSL_1_1_API
 #endif /* OPENSSL_VERSION_NUMBER >= OPENSSL_V_SERIES(1,1,0) && ... */
 
-#ifndef OPENSSL_1_1_API
+#if !defined(OPENSSL_1_1_API) || defined(LIBRESSL_VERSION_NUMBER)
 #define OpenSSL_version(v) SSLeay_version(v)
 #define tor_OpenSSL_version_num() SSLeay()
 #define RAND_OpenSSL() RAND_SSLeay()
