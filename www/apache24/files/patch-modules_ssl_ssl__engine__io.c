Backport openssl 0.9.8x patch:
http://svn.apache.org/r1719967

For discussion see:
http://marc.info/?t=145011265700003&r=1&w=2
===============================================================
--- modules/ssl/ssl_engine_io.c.orig	2015-11-19 19:55:25 UTC
+++ modules/ssl/ssl_engine_io.c
@@ -217,7 +217,7 @@ static int bio_filter_out_write(BIO *bio
      * so limit the performance impact to handshake time.
      */
 #if OPENSSL_VERSION_NUMBER < 0x0009080df
-     need_flush = !SSL_is_init_finished(outctx->filter_ctx->pssl)
+     need_flush = !SSL_is_init_finished(outctx->filter_ctx->pssl);
 #else
      need_flush = SSL_in_connect_init(outctx->filter_ctx->pssl);
 #endif
