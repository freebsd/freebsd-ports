--- ../ngx_echo_module-0.26/src/ngx_http_echo_timer.c.orig	2010-04-01 19:33:04.000000000 +0400
+++ ../ngx_echo_module-0.26/src/ngx_http_echo_timer.c	2010-04-01 19:33:09.000000000 +0400
@@ -23,7 +23,11 @@
         ctx->timer_begin.msec = (ngx_msec_t) r->start_msec;
     }
 
-    ngx_time_update(0, 0); /* force the ngx timer to update */
+#if defined nginx_version && nginx_version >= 8035
+    ngx_time_update();         /* force the ngx timer to update */
+#else
+    ngx_time_update(0, 0);     /* force the ngx timer to update */
+#endif
     tp = ngx_timeofday();
 
     dd("old sec msec: %ld %d\n", ctx->timer_begin.sec, ctx->timer_begin.msec);
@@ -52,7 +56,11 @@
         ngx_http_echo_ctx_t *ctx)
 {
     dd("Exec timer...");
-    ngx_time_update(0, 0); /* force the ngx timer to update */
+#if defined nginx_version && nginx_version >= 8035
+    ngx_time_update();         /* force the ngx timer to update */
+#else
+    ngx_time_update(0, 0);     /* force the ngx timer to update */
+#endif
 
     ctx->timer_begin = *ngx_timeofday();
     return NGX_OK;
