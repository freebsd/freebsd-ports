===================================================================
RCS file: /home/cvspublic/httpd-2.0/modules/ssl/ssl_engine_io.c,v
retrieving revision 1.124
retrieving revision 1.126
diff -u -r1.124 -r1.126
--- modules/ssl/ssl_engine_io.c	2004/07/13 18:11:22	1.124
+++ modules/ssl/ssl_engine_io.c	2004/08/17 16:31:23	1.126
@@ -564,8 +564,12 @@
         *len = bytes;
         if (inctx->mode == AP_MODE_SPECULATIVE) {
             /* We want to rollback this read. */
-            inctx->cbuf.value -= bytes;
-            inctx->cbuf.length += bytes;
+            if (inctx->cbuf.length > 0) {
+                inctx->cbuf.value -= bytes;
+                inctx->cbuf.length += bytes;
+            } else {
+                char_buffer_write(&inctx->cbuf, buf, (int)bytes);
+            }
             return APR_SUCCESS;
         }
         /* This could probably be *len == wanted, but be safe from stray
@@ -589,6 +593,10 @@
     while (1) {
 
         if (!inctx->filter_ctx->pssl) {
+            /* Ensure a non-zero error code is returned */
+            if (inctx->rc == APR_SUCCESS) {
+                inctx->rc = APR_EGENERAL;
+            }
             break;
         }
 

