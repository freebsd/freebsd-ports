--- src/http/modules/ngx_http_upstream_hash_module.c.orig	2016-02-24 14:53:24 UTC
+++ src/http/modules/ngx_http_upstream_hash_module.c
@@ -9,6 +9,9 @@
 #include <ngx_core.h>
 #include <ngx_http.h>
 
+#if (NGX_HTTP_UPSTREAM_CHECK)
+#include "ngx_http_upstream_check_module.h"
+#endif
 
 typedef struct {
     uint32_t                            hash;
@@ -235,6 +238,15 @@ ngx_http_upstream_get_hash_peer(ngx_peer
             goto next;
         }
 
+#if (NGX_HTTP_UPSTREAM_CHECK)
+        ngx_log_debug1(NGX_LOG_DEBUG_HTTP, pc->log, 0,
+            "get hash peer, check_index: %ui",
+             peer->check_index);
+        if (ngx_http_upstream_check_peer_down(peer->check_index)) {
+            goto next;
+        }
+#endif
+
         if (peer->max_fails
             && peer->fails >= peer->max_fails
             && now - peer->checked <= peer->fail_timeout)
@@ -535,6 +547,15 @@ ngx_http_upstream_get_chash_peer(ngx_pee
                 continue;
             }
 
+#if (NGX_HTTP_UPSTREAM_CHECK)
+            ngx_log_debug1(NGX_LOG_DEBUG_HTTP, pc->log, 0,
+                "get consistent_hash peer, check_index: %ui",
+                 peer->check_index);
+            if (ngx_http_upstream_check_peer_down(peer->check_index)) {
+                continue;
+            }
+#endif
+
             if (peer->server.len != server->len
                 || ngx_strncmp(peer->server.data, server->data, server->len)
                    != 0)
