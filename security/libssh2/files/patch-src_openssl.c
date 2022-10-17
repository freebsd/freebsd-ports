--- src/openssl.c.orig	2022-10-17 08:20:24 UTC
+++ src/openssl.c
@@ -653,8 +653,7 @@ _libssh2_EVP_aes_256_ctr(void)
 
 void _libssh2_openssl_crypto_init(void)
 {
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L && \
-    !defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
 #ifndef OPENSSL_NO_ENGINE
     ENGINE_load_builtin_engines();
     ENGINE_register_all_complete();
