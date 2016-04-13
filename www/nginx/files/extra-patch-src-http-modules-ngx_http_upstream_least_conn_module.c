--- src/http/modules/ngx_http_upstream_least_conn_module.c.orig	2016-01-26 14:39:32 UTC
+++ src/http/modules/ngx_http_upstream_least_conn_module.c
@@ -9,6 +9,9 @@
 #include <ngx_core.h>
 #include <ngx_http.h>
 
+#if (NGX_HTTP_UPSTREAM_CHECK)
+#include "ngx_http_upstream_check_module.h"
+#endif
 
 typedef struct {
     ngx_uint_t                        *conns;
@@ -203,6 +206,16 @@ ngx_http_upstream_get_least_conn_peer(ng
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
@@ -256,6 +269,16 @@ ngx_http_upstream_get_least_conn_peer(ng
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
             if (lcp->conns[i] * best->weight != lcp->conns[p] * peer->weight) {
                 continue;
             }
