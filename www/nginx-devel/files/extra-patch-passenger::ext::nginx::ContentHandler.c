--- ../passenger-3.0.8/ext/nginx/ContentHandler.c.orig	2011-08-10 10:35:24.000000000 +0400
+++ ../passenger-3.0.8/ext/nginx/ContentHandler.c	2011-08-10 10:36:35.000000000 +0400
@@ -336,6 +336,7 @@
     ngx_table_elt_t               *header;
     ngx_http_script_code_pt        code;
     ngx_http_script_engine_t       e, le;
+    ngx_http_core_srv_conf_t      *cscf;
     passenger_loc_conf_t          *slcf;
     passenger_main_conf_t         *main_conf;
     passenger_context_t           *context;
@@ -344,6 +345,7 @@
         ngx_http_ssl_srv_conf_t   *ssl_conf;
     #endif
     
+    cscf = ngx_http_get_module_srv_conf(r, ngx_http_core_module);
     slcf = ngx_http_get_module_loc_conf(r, ngx_http_passenger_module);
     main_conf = &passenger_main_conf;
     context = ngx_http_get_module_ctx(r, ngx_http_passenger_module);
@@ -415,11 +417,15 @@
     }
     
     /* SERVER_NAME; must be equal to HTTP_HOST without the port part */
-    tmp = memchr(r->headers_in.host->value.data, ':', r->headers_in.host->value.len);
-    if (tmp == NULL) {
-        server_name_len = r->headers_in.host->value.len;
+    if (r->headers_in.host != NULL) {
+        tmp = memchr(r->headers_in.host->value.data, ':', r->headers_in.host->value.len);
+        if (tmp == NULL) {
+            server_name_len = r->headers_in.host->value.len;
+        } else {
+            server_name_len = (int) ((const u_char *) tmp - r->headers_in.host->value.data);
+        }
     } else {
-        server_name_len = (int) ((const u_char *) tmp - r->headers_in.host->value.data);
+        server_name_len = cscf->server_name.len;
     }
     len += sizeof("SERVER_NAME") + server_name_len + 1;
     
@@ -650,8 +656,13 @@
     
     /* SERVER_NAME */
     b->last = ngx_copy(b->last, "SERVER_NAME", sizeof("SERVER_NAME"));
-    b->last = ngx_copy(b->last, r->headers_in.host->value.data,
-                       server_name_len);
+    if (r->headers_in.host != NULL) {
+        b->last = ngx_copy(b->last, r->headers_in.host->value.data,
+                           server_name_len);
+    } else {
+        b->last = ngx_copy(b->last, cscf->server_name.data,
+                           server_name_len);
+    }
     b->last = ngx_copy(b->last, "", 1);
     
     /* Various other HTTP headers. */
