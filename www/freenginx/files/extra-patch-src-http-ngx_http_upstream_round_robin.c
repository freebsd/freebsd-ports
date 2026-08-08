--- src/http/ngx_http_upstream_round_robin.c.orig
+++ src/http/ngx_http_upstream_round_robin.c
@@ -9,6 +9,9 @@
 #include <ngx_core.h>
 #include <ngx_http.h>
 
+#if (NGX_HTTP_UPSTREAM_CHECK)
+#include "ngx_http_upstream_check_module.h"
+#endif
 
 #define ngx_http_upstream_tries(p) ((p)->tries                                \
                                     + ((p)->next ? (p)->next->tries : 0))
@@ -103,7 +106,14 @@
                 peer[n].fail_timeout = server[i].fail_timeout;
                 peer[n].down = server[i].down;
                 peer[n].server = server[i].name;
-
+#if (NGX_HTTP_UPSTREAM_CHECK)
+                if (!server[i].down) {
+                    peer[n].check_index =
+                        ngx_http_upstream_check_add_peer(cf, us, &server[i].addrs[j]);
+                } else {
+                    peer[n].check_index = (ngx_uint_t) NGX_ERROR;
+                }
+#endif
                 *peerp = &peer[n];
                 peerp = &peer[n].next;
                 n++;
@@ -173,7 +183,15 @@
                 peer[n].fail_timeout = server[i].fail_timeout;
                 peer[n].down = server[i].down;
                 peer[n].server = server[i].name;
-
+#if (NGX_HTTP_UPSTREAM_CHECK)
+                if (!server[i].down) {
+                    peer[n].check_index =
+                        ngx_http_upstream_check_add_peer(cf, us, &server[i].addrs[j]);
+                }
+                else {
+                    peer[n].check_index = (ngx_uint_t) NGX_ERROR;
+                }
+#endif
                 *peerp = &peer[n];
                 peerp = &peer[n].next;
                 n++;
@@ -241,6 +259,9 @@
         peer[i].max_conns = 0;
         peer[i].max_fails = 1;
         peer[i].fail_timeout = 10;
+#if (NGX_HTTP_UPSTREAM_CHECK)
+        peer[i].check_index = (ngx_uint_t) NGX_ERROR;
+#endif
         *peerp = &peer[i];
         peerp = &peer[i].next;
     }
@@ -358,6 +379,9 @@
         peer[0].max_conns = 0;
         peer[0].max_fails = 0;
         peer[0].fail_timeout = 0;
+#if (NGX_HTTP_UPSTREAM_CHECK)
+        peer[0].check_index = (ngx_uint_t) NGX_ERROR;
+#endif
         peers->peer = peer;
 
     } else {
@@ -392,6 +416,9 @@
             peer[i].max_conns = 0;
             peer[i].max_fails = 0;
             peer[i].fail_timeout = 0;
+#if (NGX_HTTP_UPSTREAM_CHECK)
+            peer[i].check_index = (ngx_uint_t) NGX_ERROR;
+#endif
             *peerp = &peer[i];
             peerp = &peer[i].next;
         }
@@ -457,6 +484,12 @@
             goto failed;
         }
 
+#if (NGX_HTTP_UPSTREAM_CHECK)
+        if (ngx_http_upstream_check_peer_down(peer->check_index)) {
+            goto failed;
+        }
+#endif
+
         rrp->current = peer;
 
     } else {
@@ -548,8 +581,14 @@
         }
 
         if (peer->down) {
+            continue;
+        }
+
+#if (NGX_HTTP_UPSTREAM_CHECK)
+        if (ngx_http_upstream_check_peer_down(peer->check_index)) {
             continue;
         }
+#endif
 
         if (peer->max_fails
             && peer->fails >= peer->max_fails
