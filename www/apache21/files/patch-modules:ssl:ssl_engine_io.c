--- modules/ssl/ssl_engine_io.c.orig	Tue Dec  7 23:49:54 2004
+++ modules/ssl/ssl_engine_io.c	Sat Dec 18 11:56:00 2004
@@ -155,7 +155,7 @@
                                  outctx->bb);
     /* create new brigade ready for next time through */
     outctx->bb = apr_brigade_create(outctx->c->pool, outctx->c->bucket_alloc);
-    return (outctx->rc == APR_SUCCESS) ? 1 : -1;
+    return (outctx->rc == APR_SUCCESS && !outctx->c->aborted) ? 1 : -1;
 }
 
 static int bio_filter_create(BIO *bio)
