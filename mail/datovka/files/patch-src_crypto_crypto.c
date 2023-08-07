--- src/crypto/crypto.c.orig	2023-08-07 16:26:04 UTC
+++ src/crypto/crypto.c
@@ -312,7 +312,9 @@ int crypto_init(void)
 	OpenSSL_add_all_algorithms();
 
 	ERR_load_crypto_strings();
+#if OPENSSL_VERSION_NUMBER < 0x30000000L
 	ERR_load_CMS_strings();
+#endif
 	//ERR_free_strings();
 
 	if (NULL != ca_certs) {
