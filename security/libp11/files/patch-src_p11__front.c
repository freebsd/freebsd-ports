--- src/p11_front.c.orig	2017-07-03 21:05:19 UTC
+++ src/p11_front.c
@@ -380,7 +380,7 @@ int PKCS11_generate_random(PKCS11_SLOT *
 
 void ERR_load_PKCS11_strings(void)
 {
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
 	OPENSSL_init_crypto(OPENSSL_INIT_LOAD_CRYPTO_STRINGS, NULL);
 #endif
 	ERR_load_P11_strings();
