--- src/mailer.c.orig	2016-02-20 14:36:22 UTC
+++ src/mailer.c
@@ -373,7 +373,11 @@ Mailer * mailer_new(void)
 	/* ssl */
 	SSL_load_error_strings();
 	SSL_library_init();
+#ifndef OPENSSL_NO_SSL3
 	if((mailer->ssl_ctx = SSL_CTX_new(SSLv3_client_method())) == NULL
+#else
+	if((mailer->ssl_ctx = SSL_CTX_new(SSLv23_client_method())) == NULL
+#endif
 			|| SSL_CTX_set_cipher_list(mailer->ssl_ctx,
 				SSL_DEFAULT_CIPHER_LIST) != 1
 			|| SSL_CTX_load_verify_locations(mailer->ssl_ctx, NULL,
