--- libvncserver/rfbssl_openssl.c.orig	2016-12-30 13:01:28 UTC
+++ libvncserver/rfbssl_openssl.c
@@ -56,7 +56,7 @@ int rfbssl_init(rfbClientPtr cl)
 	rfbErr("OOM\n");
     } else if (!cl->screen->sslcertfile || !cl->screen->sslcertfile[0]) {
 	rfbErr("SSL connection but no cert specified\n");
-    } else if (NULL == (ctx->ssl_ctx = SSL_CTX_new(TLSv1_server_method()))) {
+    } else if (NULL == (ctx->ssl_ctx = SSL_CTX_new(TLS_server_method()))) {
 	rfbssl_error();
     } else if (SSL_CTX_use_PrivateKey_file(ctx->ssl_ctx, keyfile, SSL_FILETYPE_PEM) <= 0) {
 	rfbErr("Unable to load private key file %s\n", keyfile);
