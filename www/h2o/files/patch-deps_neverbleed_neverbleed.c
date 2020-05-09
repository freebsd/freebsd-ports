--- deps/neverbleed/neverbleed.c.orig	2019-08-12 14:09:44 UTC
+++ deps/neverbleed/neverbleed.c
@@ -630,7 +630,7 @@ static int sign_stub(struct expbuf_t *buf)
     return 0;
 }
 
-#if !OPENSSL_1_1_API
+#if !OPENSSL_1_1_API && (!defined(LIBRESSL_VERSION_NUMBER) || LIBRESSL_VERSION_NUMBER < 0x2070000fL)
 
 static void RSA_get0_key(const RSA *rsa, const BIGNUM **n, const BIGNUM **e, const BIGNUM **d)
 {
