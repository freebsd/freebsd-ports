--- src/ngx_http_lua_time.c.orig	2025-10-24 15:04:57 UTC
+++ src/ngx_http_lua_time.c
@@ -28,7 +28,16 @@ ngx_http_lua_ffi_req_start_time(ngx_http_request_t *r)
 double
 ngx_http_lua_ffi_req_start_time(ngx_http_request_t *r)
 {
+#if defined(freenginx)
+    ngx_time_t              *tp;
+
+    tp = ngx_timeofday();
+
+    return (tp->sec + tp->msec / 1000.0)
+           - (double) (ngx_current_msec - r->start_time) / 1000.0;
+#else
     return r->start_sec + r->start_msec / 1000.0;
+#endif
 }
 
 
