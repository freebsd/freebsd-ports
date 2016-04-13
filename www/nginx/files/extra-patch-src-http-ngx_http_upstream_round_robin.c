--- src/http/ngx_http_upstream_round_robin.c.orig	2016-01-26 14:39:33 UTC
+++ src/http/ngx_http_upstream_round_robin.c
@@ -9,6 +9,9 @@
 #include <ngx_core.h>
 #include <ngx_http.h>
 
+#if (NGX_HTTP_UPSTREAM_CHECK)
+#include "ngx_http_upstream_check_module.h"
+#endif
 
 #define ngx_http_upstream_tries(p) ((p)->number                               \
                                     + ((p)->next ? (p)->next->number : 0))
@@ -92,6 +95,14 @@ ngx_http_upstream_init_round_robin(ngx_c
                 peer[n].fail_timeout = server[i].fail_timeout;
                 peer[n].down = server[i].down;
                 peer[n].server = server[i].name;
+#if (NGX_HTTP_UPSTREAM_CHECK)
+                if (!server[i].down) {
+                    peers->peer[n].check_index =
+                        ngx_http_upstream_check_add_peer(cf, us, &server[i].addrs[j]);
+                } else {
+                    peers->peer[n].check_index = (ngx_uint_t) NGX_ERROR;
+                }
+#endif
                 n++;
             }
         }
@@ -148,6 +159,15 @@ ngx_http_upstream_init_round_robin(ngx_c
                 peer[n].fail_timeout = server[i].fail_timeout;
                 peer[n].down = server[i].down;
                 peer[n].server = server[i].name;
+#if (NGX_HTTP_UPSTREAM_CHECK)
+                if (!server[i].down) {
+                    backup->peer[n].check_index =
+                        ngx_http_upstream_check_add_peer(cf, us, &server[i].addrs[j]);
+                }
+                else {
+                    backup->peer[n].check_index = (ngx_uint_t) NGX_ERROR;
+                }
+#endif
                 n++;
             }
         }
@@ -207,6 +227,9 @@ ngx_http_upstream_init_round_robin(ngx_c
         peer[i].current_weight = 0;
         peer[i].max_fails = 1;
         peer[i].fail_timeout = 10;
+#if (NGX_HTTP_UPSTREAM_CHECK)
+        peers->peer[i].check_index = (ngx_uint_t) NGX_ERROR;
+#endif
     }
 
     us->peer.data = peers;
@@ -316,7 +339,9 @@ ngx_http_upstream_create_round_robin_pee
         peer[0].current_weight = 0;
         peer[0].max_fails = 1;
         peer[0].fail_timeout = 10;
-
+#if (NGX_HTTP_UPSTREAM_CHECK)
+        peers->peer[0].check_index = (ngx_uint_t) NGX_ERROR;
+#endif
     } else {
 
         for (i = 0; i < ur->naddrs; i++) {
@@ -356,6 +381,9 @@ ngx_http_upstream_create_round_robin_pee
             peer[i].current_weight = 0;
             peer[i].max_fails = 1;
             peer[i].fail_timeout = 10;
+#if (NGX_HTTP_UPSTREAM_CHECK)
+            peers->peer[i].check_index = (ngx_uint_t) NGX_ERROR;
+#endif
         }
     }
 
@@ -415,6 +443,12 @@ ngx_http_upstream_get_round_robin_peer(n
             goto failed;
         }
 
+#if (NGX_HTTP_UPSTREAM_CHECK)
+        if (ngx_http_upstream_check_peer_down(peer->check_index)) {
+            goto failed;
+        }
+#endif
+
     } else {
 
         /* there are several peers */
@@ -507,6 +541,12 @@ ngx_http_upstream_get_peer(ngx_http_upst
             continue;
         }
 
+#if (NGX_HTTP_UPSTREAM_CHECK)
+        if (ngx_http_upstream_check_peer_down(peer->check_index)) {
+            continue;
+        }
+#endif
+
         if (peer->max_fails
             && peer->fails >= peer->max_fails
             && now - peer->checked <= peer->fail_timeout)
