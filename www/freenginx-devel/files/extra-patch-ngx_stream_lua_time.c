--- ../stream-lua-nginx-module-0.0.17R4/src/ngx_stream_lua_time.c.orig	2026-01-16 13:37:35.591811000 -0500
+++ ../stream-lua-nginx-module-0.0.17R4/src/ngx_stream_lua_time.c	2026-01-16 13:44:41.641936000 -0500
@@ -36,7 +36,21 @@
 double
 ngx_stream_lua_ffi_req_start_time(ngx_stream_lua_request_t *r)
 {
+#if defined freenginx
+    ngx_time_t              *tp;
+
+    tp = ngx_timeofday();
+    tp->sec -= (ngx_current_msec - r->session->start_time) / 1000;
+    tp->msec -= (ngx_current_msec - r->session->start_time) % 1000;
+    if (tp->msec > NGX_MAX_INT_T_VALUE) {
+        tp->msec += 1000;
+        tp->sec -= 1;
+    }
+
+    return tp->sec + tp->msec / 1000.0;
+#else
     return r->session->start_sec + r->session->start_msec / 1000.0;
+#endif
 }
 
 
