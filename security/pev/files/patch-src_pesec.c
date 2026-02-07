--- src/pesec.c.orig	2018-10-20 11:48:33 UTC
+++ src/pesec.c
@@ -225,7 +225,9 @@ static int parse_pkcs7_data(const options_t *options, 
 	PKCS7 *p7 = NULL;
 	BIO *in = NULL;
 
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 	CRYPTO_malloc_init();
+#endif
 	ERR_load_crypto_strings();
 	OpenSSL_add_all_algorithms();
 
