--- ../nginx_uploadprogress_module/ngx_http_uploadprogress_module.c.orig	2009-06-26 15:32:01.000000000 +0400
+++ ../nginx_uploadprogress_module/ngx_http_uploadprogress_module.c	2009-06-26 15:38:30.000000000 +0400
@@ -187,8 +187,9 @@
         if (i) {
             start_p = p += 14;
             while (p < r->args.data + r->args.len) {
-                if (*p++ != '&') {
-                    continue;
+                if (*p++ == '&') {
+                    p--;
+                    break;
                 }
             }
 
@@ -799,7 +799,7 @@ ngx_clean_old_connections(ngx_event_t * ev)
     ngx_http_uploadprogress_ctx_t   *ctx;
     ngx_slab_pool_t                 *shpool;
     ngx_rbtree_node_t               *node;
-    ngx_http_uploadprogress_node_t  *up;
+    ngx_http_uploadprogress_node_t  *up, *upprev;
     time_t                           now = ngx_time();
     int                              count = 0;
 
@@ -822,6 +822,7 @@ ngx_clean_old_connections(ngx_event_t * ev)
         }
 
         up = (ngx_http_uploadprogress_node_t *) node;
+        upprev = up->prev;
 
         ngx_log_debug3(NGX_LOG_DEBUG_HTTP, shm_zone->shm.log, 0,
                        "uploadprogress clean: scanning %08XD (req done %ui) timeout at %T",
@@ -840,7 +841,7 @@ ngx_clean_old_connections(ngx_event_t * ev)
         }
         else
             count++;
-        node = (ngx_rbtree_node_t *) up->prev;
+        node = (ngx_rbtree_node_t *) upprev;
     }
 
     ngx_log_debug3(NGX_LOG_DEBUG_HTTP, shm_zone->shm.log, 0,
