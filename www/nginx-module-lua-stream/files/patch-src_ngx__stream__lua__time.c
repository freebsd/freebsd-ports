--- src/ngx_stream_lua_time.c.orig	2025-10-24 14:55:36 UTC
+++ src/ngx_stream_lua_time.c
@@ -36,7 +36,17 @@ ngx_stream_lua_ffi_req_start_time(ngx_stream_lua_reque
 double
 ngx_stream_lua_ffi_req_start_time(ngx_stream_lua_request_t *r)
 {
+#if defined(freenginx)
+    ngx_time_t              *tp;
+
+    tp = ngx_timeofday();
+
+    return (tp->sec + tp->msec / 1000.0)
+           - (double) (ngx_current_msec - r->session->start_time)
+             / 1000.0;
+#else
     return r->session->start_sec + r->session->start_msec / 1000.0;
+#endif
 }
 
 
