--- module-webif-lib.c.orig	2015-06-30 13:06:41 UTC
+++ module-webif-lib.c
@@ -864,6 +864,7 @@ SSL_CTX *SSL_Webif_Init(void)
 	CRYPTO_set_dynlock_lock_callback(SSL_dyn_lock_function);
 	CRYPTO_set_dynlock_destroy_callback(SSL_dyn_destroy_function);
 
+#ifndef OPENSSL_NO_SSL3
 	if(cfg.http_force_sslv3)
 	{
 		ctx = SSL_CTX_new(SSLv3_server_method());
@@ -876,6 +877,7 @@ SSL_CTX *SSL_Webif_Init(void)
 		SSL_CTX_set_cipher_list(ctx, SSL_TXT_RC4);
 	}
 	else
+#endif
 		{ ctx = SSL_CTX_new(SSLv23_server_method()); }
 
 	char path[128];
