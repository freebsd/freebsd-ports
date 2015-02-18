--- src/common/tortls.c.orig    2014-09-23 02:41:52.000000000 +0200
+++ src/common/tortls.c 2014-09-30 11:17:38.795307786 +0200
@@ -1347,8 +1347,6 @@
   }
   /* Don't actually allow compression; it uses ram and time, but the data
    * we transmit is all encrypted anyway. */
-  if (result->ctx->comp_methods)
-    result->ctx->comp_methods = NULL;
 #ifdef SSL_MODE_RELEASE_BUFFERS
   SSL_CTX_set_mode(result->ctx, SSL_MODE_RELEASE_BUFFERS);
 #endif
