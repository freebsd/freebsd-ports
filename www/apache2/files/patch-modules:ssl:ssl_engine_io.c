--- modules/ssl/ssl_engine_io.c.orig	Fri Dec 17 23:14:23 2004
+++ modules/ssl/ssl_engine_io.c	Fri Dec 17 23:15:04 2004
@@ -153,7 +153,7 @@
 
     outctx->rc = ap_pass_brigade(outctx->filter_ctx->pOutputFilter->next,
                                  outctx->bb);
-    return (outctx->rc == APR_SUCCESS) ? 1 : -1;
+    return (outctx->rc == APR_SUCCESS && !outctx->c->aborted) ? 1 : -1;
 }
 
 static int bio_filter_create(BIO *bio)
