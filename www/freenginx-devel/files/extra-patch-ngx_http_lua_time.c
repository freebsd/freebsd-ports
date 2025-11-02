--- ../lua-nginx-module-0.10.29/src/ngx_http_lua_time.c.orig	2025-01-17 00:24:35.000000000 -0500
+++ ../lua-nginx-module-0.10.29/src/ngx_http_lua_time.c	2025-11-02 00:11:45.551096000 -0400
@@ -28,7 +28,21 @@
 double
 ngx_http_lua_ffi_req_start_time(ngx_http_request_t *r)
 {
+#if defined freenginx
+    ngx_time_t              *tp;
+
+    tp = ngx_timeofday();
+    tp->sec -= (ngx_current_msec - r->start_time) / 1000;
+    tp->msec -= (ngx_current_msec - r->start_time) % 1000;
+    if (tp->msec > NGX_MAX_INT_T_VALUE) {
+        tp->msec += 1000;
+        tp->sec -= 1;
+    }
+
+    return tp->sec + tp->msec / 1000.0;
+#else
     return r->start_sec + r->start_msec / 1000.0;
+#endif
 }
 
 
