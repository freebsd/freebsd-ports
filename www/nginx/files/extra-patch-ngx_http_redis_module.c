--- ../ngx_http_redis-0.3.0/ngx_http_redis_module.c.orig	2009-12-23 16:55:12.000000000 +0300
+++ ../ngx_http_redis-0.3.0/ngx_http_redis_module.c	2009-12-24 18:09:13.000000000 +0300
@@ -343,17 +343,29 @@
 ngx_http_redis_process_header(ngx_http_request_t *r)
 {
     u_char                    *p, *len;
-    u_int                      c = 0;
+    u_int                      c, try;
     ngx_str_t                  line;
     ngx_http_upstream_t       *u;
     ngx_http_redis_ctx_t      *ctx;
 
+    c = try = 0;
+
     u = r->upstream;
 
+    p = u->buffer.pos;
+
+    if (*p == '+') {
+        try = 2;
+    } else if (*p == '-') {
+        try = 1;
+    } else {
+        goto no_valid;
+    }
+
     for (p = u->buffer.pos; p < u->buffer.last; p++) {
         if (*p == LF) {
             c++;
-            if (c == 2) {
+            if (c == try) {
                 goto found;
             }
         }
@@ -379,8 +391,8 @@
         ngx_log_error(NGX_LOG_INFO, r->connection->log, 0,
                       "error was received from redis");
 
-        u->headers_in.status_n = 404;
-        u->state->status = 404;
+        u->headers_in.status_n = 502;
+        u->state->status = 502;
 
         return NGX_OK;
     }
