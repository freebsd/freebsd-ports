--- src/events.c.orig	2014-12-20 13:09:17.000000000 +0100
+++ src/events.c	2015-09-23 21:21:12.750495743 +0200
@@ -294,7 +294,7 @@ int gg_session_init_ssl(struct gg_sessio
 	}
 
 	if (gs->ssl_ctx == NULL) {
-		gs->ssl_ctx = SSL_CTX_new(SSLv3_client_method());
+		gs->ssl_ctx = SSL_CTX_new(SSLv23_client_method());
 
 		if (gs->ssl_ctx == NULL) {
 			ERR_error_string_n(ERR_get_error(), buf, sizeof(buf));
