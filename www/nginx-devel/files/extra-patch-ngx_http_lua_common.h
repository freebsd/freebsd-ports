--- ../lua-nginx-module-0.10.8/src/ngx_http_lua_common.h.orig	2017-04-15 10:55:20.591680000 -0400
+++ ../lua-nginx-module-0.10.8/src/ngx_http_lua_common.h	2017-04-15 10:55:50.449108000 -0400
@@ -199,6 +199,12 @@
                                                 of reqeusts */
     ngx_uint_t           malloc_trim_req_count;
 
+#if nginx_version >= 1011011
+    /* the following 2 fields are only used by ngx.req.raw_headers() for now */
+    ngx_buf_t          **busy_buf_ptrs;
+    ngx_int_t            busy_buf_ptr_count;
+#endif
+
     unsigned             requires_header_filter:1;
     unsigned             requires_body_filter:1;
     unsigned             requires_capture_filter:1;
