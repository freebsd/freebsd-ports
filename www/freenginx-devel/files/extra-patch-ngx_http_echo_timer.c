--- ../echo-nginx-module-4eeda3c/src/ngx_http_echo_timer.c.orig	2025-10-21 16:47:54.085370000 -0400
+++ ../echo-nginx-module-4eeda3c/src/ngx_http_echo_timer.c	2025-10-21 16:50:55.878182000 -0400
@@ -32,9 +32,8 @@
         ngx_http_set_ctx(r, ctx, ngx_http_echo_module);
     }
 
-    if (ctx->timer_begin.sec == 0) {
-        ctx->timer_begin.sec  = r->start_sec;
-        ctx->timer_begin.msec = (ngx_msec_t) r->start_msec;
+    if (ctx->timer_begin.time == 0) {
+        ctx->timer_begin.time  = r->start_time;
     }
 
     /* force the ngx timer to update */
