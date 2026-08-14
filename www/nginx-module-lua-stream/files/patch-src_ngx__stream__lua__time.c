--- src/ngx_stream_lua_time.c.orig
+++ src/ngx_stream_lua_time.c
@@ -36,7 +36,11 @@ ngx_stream_lua_ffi_now(void)
 double
 ngx_stream_lua_ffi_req_start_time(ngx_stream_lua_request_t *r)
 {
+#if defined(freenginx)
+    return r->session->start_time / 1000.0;
+#else
     return r->session->start_sec + r->session->start_msec / 1000.0;
+#endif
 }
