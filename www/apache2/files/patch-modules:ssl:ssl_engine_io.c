===================================================================
RCS file: /home/cvspublic/httpd-2.0/modules/ssl/ssl_engine_io.c,v
retrieving revision 1.100.2.11
retrieving revision 1.100.2.12
diff -u -r1.100.2.11 -r1.100.2.12
--- modules/ssl/ssl_engine_io.c	2004/02/09 20:53:20	1.100.2.11
+++ modules/ssl/ssl_engine_io.c	2004/03/07 22:03:16	1.100.2.12
@@ -821,9 +821,11 @@
                                sizeof(HTTP_ON_HTTPS_PORT) - 1, \
                                alloc)
 
-static void ssl_io_filter_disable(ap_filter_t *f)
+static void ssl_io_filter_disable(SSLConnRec *sslconn, ap_filter_t *f)
 {
     bio_filter_in_ctx_t *inctx = f->ctx;
+    SSL_free(inctx->ssl);
+    sslconn->ssl = NULL;
     inctx->ssl = NULL;
     inctx->filter_ctx->pssl = NULL;
 }
@@ -845,7 +847,7 @@
             ssl_log_ssl_error(APLOG_MARK, APLOG_INFO, f->c->base_server);
 
             sslconn->non_ssl_request = 1;
-            ssl_io_filter_disable(f);
+            ssl_io_filter_disable(sslconn, f);
 
             /* fake the request line */
             bucket = HTTP_ON_HTTPS_PORT_BUCKET(f->c->bucket_alloc);


