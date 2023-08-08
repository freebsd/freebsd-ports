--- deps/neverbleed/neverbleed.c.orig	2019-08-12 14:09:44 UTC
+++ deps/neverbleed/neverbleed.c
@@ -45,7 +45,9 @@
 #endif
 #include "neverbleed.h"

-#if (!defined(LIBRESSL_VERSION_NUMBER) && OPENSSL_VERSION_NUMBER >= 0x1010000fL)
+#if (OPENSSL_VERSION_NUMBER >= 0x1010000fL \
+    || (defined(LIBRESSL_VERSION_NUMBER) \
+    && LIBRESSL_VERSION_NUMBER >= 0x3050300fL))
 #define OPENSSL_1_1_API 1
 #else
 #define OPENSSL_1_1_API 0
@@ -630,7 +632,7 @@ static int sign_stub(struct expbuf_t *buf)
     return 0;
 }
 
-#if !OPENSSL_1_1_API
+#if !OPENSSL_1_1_API && (!defined(LIBRESSL_VERSION_NUMBER) || LIBRESSL_VERSION_NUMBER < 0x2070000fL)
 
 static void RSA_get0_key(const RSA *rsa, const BIGNUM **n, const BIGNUM **e, const BIGNUM **d)
 {
