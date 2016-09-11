--- src/events.c.orig	2014-12-20 12:09:17 UTC
+++ src/events.c
@@ -294,7 +294,11 @@ int gg_session_init_ssl(struct gg_sessio
 	}
 
 	if (gs->ssl_ctx == NULL) {
+#ifndef OPENSSL_NO_SSL3
 		gs->ssl_ctx = SSL_CTX_new(SSLv3_client_method());
+#else
+		gs->ssl_ctx = SSL_CTX_new(SSLv23_client_method());
+#endif
 
 		if (gs->ssl_ctx == NULL) {
 			ERR_error_string_n(ERR_get_error(), buf, sizeof(buf));
