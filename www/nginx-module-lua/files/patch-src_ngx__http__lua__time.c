--- src/ngx_http_lua_time.c.orig
+++ src/ngx_http_lua_time.c
@@ -28,7 +28,11 @@
 double
 ngx_http_lua_ffi_req_start_time(ngx_http_request_t *r)
 {
+#if defined(freenginx)
+    return r->start_time / 1000.0;
+#else
     return r->start_sec + r->start_msec / 1000.0;
+#endif
 }
 
 
