--- src/http/modules/ngx_http_upstream_least_conn_module.c.orig	2016-02-24 14:53:24 UTC
+++ src/http/modules/ngx_http_upstream_least_conn_module.c
@@ -9,6 +9,9 @@
 #include <ngx_core.h>
 #include <ngx_http.h>
 
+#if (NGX_HTTP_UPSTREAM_CHECK)
+#include "ngx_http_upstream_check_module.h"
+#endif
 
 static ngx_int_t ngx_http_upstream_init_least_conn_peer(ngx_http_request_t *r,
     ngx_http_upstream_srv_conf_t *us);
@@ -148,6 +151,16 @@ ngx_http_upstream_get_least_conn_peer(ng
             continue;
         }
 
+#if (NGX_HTTP_UPSTREAM_CHECK)
+        ngx_log_debug1(NGX_LOG_DEBUG_HTTP, pc->log, 0,
+                "get least_conn peer, check_index: %ui",
+                peer->check_index);
+
+        if (ngx_http_upstream_check_peer_down(peer->check_index)) {
+            continue;
+        }
+#endif
+
         if (peer->max_fails
             && peer->fails >= peer->max_fails
             && now - peer->checked <= peer->fail_timeout)
@@ -199,6 +212,16 @@ ngx_http_upstream_get_least_conn_peer(ng
                 continue;
             }
 
+#if (NGX_HTTP_UPSTREAM_CHECK)
+            ngx_log_debug1(NGX_LOG_DEBUG_HTTP, pc->log, 0,
+                    "get least_conn peer, check_index: %ui",
+                    peer->check_index);
+
+            if (ngx_http_upstream_check_peer_down(peer->check_index)) {
+                continue;
+            }
+#endif
+
             if (peer->conns * best->weight != best->conns * peer->weight) {
                 continue;
             }
