Cherry-picked from upstream
https://redmine.lighttpd.net/projects/lighttpd/repository/revisions/1ca52fdce3b87f7748dd5db6f59d738ed7a9efe1/diff

--- src/network.c.orig	2015-12-04 21:13:47 UTC
+++ src/network.c
@@ -769,7 +769,7 @@ int network_init(server *srv) {
 
 		if (!s->ssl_use_sslv2) {
 			/* disable SSLv2 */
-			if (!(SSL_OP_NO_SSLv2 & SSL_CTX_set_options(s->ssl_ctx, SSL_OP_NO_SSLv2))) {
+			if ((SSL_OP_NO_SSLv2 & SSL_CTX_set_options(s->ssl_ctx, SSL_OP_NO_SSLv2)) != SSL_OP_NO_SSLv2) {
 				log_error_write(srv, __FILE__, __LINE__, "ss", "SSL:",
 						ERR_error_string(ERR_get_error(), NULL));
 				return -1;
@@ -778,7 +778,7 @@ int network_init(server *srv) {
 
 		if (!s->ssl_use_sslv3) {
 			/* disable SSLv3 */
-			if (!(SSL_OP_NO_SSLv3 & SSL_CTX_set_options(s->ssl_ctx, SSL_OP_NO_SSLv3))) {
+			if ((SSL_OP_NO_SSLv3 & SSL_CTX_set_options(s->ssl_ctx, SSL_OP_NO_SSLv3)) != SSL_OP_NO_SSLv3) {
 				log_error_write(srv, __FILE__, __LINE__, "ss", "SSL:",
 						ERR_error_string(ERR_get_error(), NULL));
 				return -1;
