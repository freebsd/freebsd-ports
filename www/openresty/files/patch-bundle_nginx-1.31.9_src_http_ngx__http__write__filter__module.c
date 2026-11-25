--- bundle/nginx-1.31.9/src/http/ngx_http_write_filter_module.c.orig	2026-11-25 07:53:13 UTC
+++ bundle/nginx-1.31.9/src/http/ngx_http_write_filter_module.c
@@ -47,7 +47,7 @@ ngx_http_write_filter(ngx_http_request_t *r, ngx_chain
 ngx_int_t
 ngx_http_write_filter(ngx_http_request_t *r, ngx_chain_t *in)
 {
-    off_t                      size, sent, nsent, limit;
+    off_t                      size, sent, psent, nsent, limit;
     ngx_uint_t                 last, flush, sync;
     ngx_msec_t                 delay;
     ngx_chain_t               *cl, *ln, **ll, *chain;
@@ -308,13 +308,14 @@ ngx_http_write_filter(ngx_http_request_t *r, ngx_chain
 
     if (r->limit_rate) {
 
+        psent = sent;
         nsent = c->sent;
 
         if (r->limit_rate_after) {
 
-            sent -= r->limit_rate_after;
-            if (sent < 0) {
-                sent = 0;
+            psent -= r->limit_rate_after;
+            if (psent < 0) {
+                psent = 0;
             }
 
             nsent -= r->limit_rate_after;
@@ -323,7 +324,7 @@ ngx_http_write_filter(ngx_http_request_t *r, ngx_chain
             }
         }
 
-        delay = (ngx_msec_t) ((nsent - sent) * 1000 / r->limit_rate);
+        delay = (ngx_msec_t) ((nsent - psent) * 1000 / r->limit_rate);
 
         if (delay > 0) {
             c->write->delayed = 1;
@@ -331,7 +332,7 @@ ngx_http_write_filter(ngx_http_request_t *r, ngx_chain
         }
     }
 
-    if (chain && c->write->ready && !c->write->delayed) {
+    if (chain && c->write->ready && !c->write->delayed && sent != c->sent) {
         ngx_post_event(c->write, &ngx_posted_next_events);
     }
 
