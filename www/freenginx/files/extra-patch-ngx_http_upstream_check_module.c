--- ../nginx_upstream_check_module-9aecf15/ngx_http_upstream_check_module.c.orig
+++ ../nginx_upstream_check_module-9aecf15/ngx_http_upstream_check_module.c
@@ -1844,6 +1844,7 @@
 ngx_http_upstream_check_parse_fastcgi_status(ngx_http_upstream_check_ctx_t *ctx,
     ngx_buf_t *b, ngx_http_status_t *status)
 {
+    ngx_uint_t count = 0;
     u_char      c, ch, *p, *name_s, *name_e;
     ngx_flag_t  find;
 
@@ -1870,7 +1871,7 @@
         "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
         "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
 
-    status->count = 0;
+    count = 0;
     status->code = 0;
     find = 0;
     name_s = name_e = NULL;
@@ -1979,7 +1980,7 @@
                     }
 
                     status->code = status->code * 10 + ch - '0';
-                    if (status->count++ != 0) {
+                    if (count++ != 0) {
                         return NGX_ERROR;
                     }
                 }
@@ -1999,7 +2000,7 @@
 
                 status->code = status->code * 10 + ch - '0';
 
-                if (++status->count == 3) {
+                if (++count == 3) {
                     return NGX_DONE;
                 }
             }
@@ -2097,6 +2098,7 @@
 ngx_http_upstream_check_parse_status_line(ngx_http_upstream_check_ctx_t *ctx,
     ngx_buf_t *b, ngx_http_status_t *status)
 {
+    ngx_uint_t count = 0;
     u_char ch, *p;
     enum {
         sw_start = 0,
@@ -2218,7 +2220,7 @@
 
             status->code = status->code * 10 + ch - '0';
 
-            if (++status->count == 3) {
+            if (++count == 3) {
                 state = sw_space_after_status;
                 status->start = p - 2;
             }
