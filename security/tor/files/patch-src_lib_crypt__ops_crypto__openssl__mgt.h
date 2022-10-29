--- src/lib/crypt_ops/crypto_openssl_mgt.h.orig	2022-10-17 12:37:26 UTC
+++ src/lib/crypt_ops/crypto_openssl_mgt.h
@@ -54,8 +54,7 @@
 #define DISABLE_ENGINES
 #endif
 
-#if OPENSSL_VERSION_NUMBER >= OPENSSL_VER(1,1,0,0,5) && \
-  !defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER >= OPENSSL_VER(1,1,0,0,5)
 /* OpenSSL as of 1.1.0pre4 has an "new" thread API, which doesn't require
  * setting up various callbacks.
  *
