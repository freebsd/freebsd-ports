--- src/network.c	2010-01-28 10:43:33.829209750 -0500
+++ src/network.c	2010-01-28 10:44:22.639208732 -0500
@@ -525,7 +525,7 @@ int network_init(server *srv) {
 
 		if (!s->ssl_use_sslv2) {
 			/* disable SSLv2 */
-			if (SSL_OP_NO_SSLv2 != SSL_CTX_set_options(s->ssl_ctx, SSL_OP_NO_SSLv2)) {
+			if (!(SSL_OP_NO_SSLv2 & SSL_CTX_set_options(s->ssl_ctx, SSL_OP_NO_SSLv2))) {
 				log_error_write(srv, __FILE__, __LINE__, "ss", "SSL:",
 						ERR_error_string(ERR_get_error(), NULL));
 				return -1;
