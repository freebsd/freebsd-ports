--- src/http/ngx_http_write_filter_module.c.orig	2026-10-27 15:05:09 UTC
+++ src/http/ngx_http_write_filter_module.c
@@ -336,7 +336,7 @@ ngx_http_write_filter(ngx_http_request_t *r, ngx_chain
         }
     }
 
-    if (chain && c->write->ready && !c->write->delayed) {
+    if (chain && c->write->ready && !c->write->delayed && sent != c->sent) {
         ngx_post_event(c->write, &ngx_posted_next_events);
     }
 
