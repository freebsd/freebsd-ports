--- src/contrib/libpdel/http/http_server.c.orig	2013-06-11 11:00:00.000000000 +0200
+++ src/contrib/libpdel/http/http_server.c	2015-03-23 21:01:49.295512000 +0100
@@ -197,7 +197,7 @@ http_server_start(struct pevent_ctx *ctx
 		_http_ssl_init();
 
 		/* Initialize SSL context for this server */
-		if ((serv->ssl = SSL_CTX_new(SSLv2_server_method())) == NULL) {
+		if ((serv->ssl = SSL_CTX_new(SSLv23_server_method())) == NULL) {
 			ssl_log(http_server_ssl_logger, serv);
 			goto fail;
 		}
