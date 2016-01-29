--- src/login-common/ssl-proxy-openssl.c.orig	2011-01-20 21:16:59 UTC
+++ src/login-common/ssl-proxy-openssl.c
@@ -21,6 +21,7 @@
 #include <openssl/ssl.h>
 #include <openssl/err.h>
 #include <openssl/rand.h>
+#include <openssl/comp.h>
 
 #define DOVECOT_SSL_DEFAULT_CIPHER_LIST "ALL:!LOW:!SSLv2"
 /* Check every 30 minutes if parameters file has been updated */
@@ -817,7 +818,7 @@ static void ssl_proxy_ctx_init(SSL_CTX *
 {
 	const char *cafile;
 
-	SSL_CTX_set_options(ssl_ctx, SSL_OP_ALL);
+	SSL_CTX_set_options(ssl_ctx, SSL_OP_ALL | SSL_OP_NO_SSLv2 | SSL_OP_NO_SSLv3);
 
 	cafile = getenv("SSL_CA_FILE");
 	if (cafile != NULL) {
