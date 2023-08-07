--- src/pki_init.c.orig	2023-06-27 08:58:28.488119000 +0200
+++ src/pki_init.c	2023-06-27 13:17:52.664235000 +0200
@@ -159,8 +159,10 @@
 		OpenSSL_add_all_ciphers();
 		OpenSSL_pthread_init();
 
+#if OPENSSL_VERSION_NUMBER < 0x30000000
 		ERR_load_ERR_strings();
 		ERR_load_crypto_strings();
+#endif
 
 		PRQP_init_all_services();
 		PKI_X509_SCEP_init();
