--- ../echo-nginx-module-4eeda3c/src/ngx_http_echo_timer.c.orig	2024-08-17 08:36:17.000000000 -0400
+++ ../echo-nginx-module-4eeda3c/src/ngx_http_echo_timer.c	2025-11-01 22:07:05.628904000 -0400
@@ -33,8 +33,20 @@
     }
 
     if (ctx->timer_begin.sec == 0) {
+#if defined freenginx
+        tp = ngx_timeofday();
+
+        tp->sec -= (ngx_current_msec - r->start_time) / 1000;
+        tp->msec -= (ngx_current_msec - r->start_time) % 1000;
+        if (tp->msec > NGX_MAX_INT_T_VALUE) {
+            tp->msec += 1000;
+            tp->sec -= 1;
+        }
+        ctx->timer_begin = *tp;
+#else
         ctx->timer_begin.sec  = r->start_sec;
         ctx->timer_begin.msec = (ngx_msec_t) r->start_msec;
+#endif
     }
 
     /* force the ngx timer to update */
