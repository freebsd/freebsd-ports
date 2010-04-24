--- src/network.c.orig	2010-02-02 00:28:20.000000000 +0100
+++ src/network.c	2010-04-24 13:43:10.000000000 +0200
@@ -525,7 +525,7 @@
 
 		if (!s->ssl_use_sslv2) {
 			/* disable SSLv2 */
-			if (SSL_OP_NO_SSLv2 != SSL_CTX_set_options(s->ssl_ctx, SSL_OP_NO_SSLv2)) {
+			if (!(SSL_OP_NO_SSLv2 & SSL_CTX_set_options(s->ssl_ctx, SSL_OP_NO_SSLv2))) {
 				log_error_write(srv, __FILE__, __LINE__, "ss", "SSL:",
 						ERR_error_string(ERR_get_error(), NULL));
 				return -1;
