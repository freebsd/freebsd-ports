--- src/mailer.c.orig	2012-12-06 20:03:29.000000000 +0100
+++ src/mailer.c	2015-09-26 16:07:02.862928808 +0200
@@ -373,7 +373,7 @@ Mailer * mailer_new(void)
 	/* ssl */
 	SSL_load_error_strings();
 	SSL_library_init();
-	if((mailer->ssl_ctx = SSL_CTX_new(SSLv3_client_method())) == NULL
+	if((mailer->ssl_ctx = SSL_CTX_new(SSLv23_client_method())) == NULL
 			|| SSL_CTX_set_cipher_list(mailer->ssl_ctx,
 				SSL_DEFAULT_CIPHER_LIST) != 1
 			|| SSL_CTX_load_verify_locations(mailer->ssl_ctx, NULL,
