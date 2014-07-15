--- src/http/ngx_http_upstream.h.orig	2010-01-14 04:20:57.000000000 +0300
+++ src/http/ngx_http_upstream.h	2010-01-14 04:22:00.000000000 +0300
@@ -105,6 +105,10 @@
 
     ngx_array_t                     *servers;  /* ngx_http_upstream_server_t */
 
+    ngx_array_t                     *values;
+    ngx_array_t                     *lengths;
+    ngx_uint_t                       retries;
+
     ngx_uint_t                       flags;
     ngx_str_t                        host;
     u_char                          *file_name;
