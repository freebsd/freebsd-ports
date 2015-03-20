--- src/login-common/ssl-proxy-openssl.c.orig	2015-03-19 11:57:04.578367000 -0500
+++ src/login-common/ssl-proxy-openssl.c	2015-03-19 11:57:21.859436000 -0500
@@ -818,7 +818,7 @@ static void ssl_proxy_ctx_init(SSL_CTX *
 {
 	const char *cafile;
 
-	SSL_CTX_set_options(ssl_ctx, SSL_OP_ALL);
+	SSL_CTX_set_options(ssl_ctx, SSL_OP_ALL | SSL_OP_NO_SSLv2 | SSL_OP_NO_SSLv3);
 
 	cafile = getenv("SSL_CA_FILE");
 	if (cafile != NULL) {
