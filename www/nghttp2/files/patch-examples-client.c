--- examples/client.c.orig	2018-02-02 12:19:16 UTC
+++ examples/client.c
@@ -375,7 +375,9 @@ static void init_ssl_ctx(SSL_CTX *ssl_ct
   SSL_CTX_set_mode(ssl_ctx, SSL_MODE_AUTO_RETRY);
   SSL_CTX_set_mode(ssl_ctx, SSL_MODE_RELEASE_BUFFERS);
   /* Set NPN callback */
+#ifndef OPENSSL_NO_NEXTPROTONEG
   SSL_CTX_set_next_proto_select_cb(ssl_ctx, select_next_proto_cb, NULL);
+#endif
 }
 
 static void ssl_handshake(SSL *ssl, int fd) {
