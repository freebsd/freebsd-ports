--- src/http/ngx_http_upstream_round_robin.c.orig
+++ src/http/ngx_http_upstream_round_robin.c	2026-05-04 16:03:21.659464946 +0000
@@ -10,6 +10,10 @@
 #include <ngx_http.h>
 #include <ngx_md5.h>
 
+#if (NGX_HTTP_UPSTREAM_CHECK)
+#include "ngx_http_upstream_check_module.h"
+#endif
+
 
 #define ngx_http_upstream_tries(p) ((p)->tries                                \
                                     + ((p)->next ? (p)->next->tries : 0))
@@ -196,6 +200,16 @@
                 peer[n].down = server[i].down;
                 peer[n].server = server[i].name;
 
+#if (NGX_HTTP_UPSTREAM_CHECK)
+                if (!server[i].down) {
+                    peer[n].check_index =
+                        ngx_http_upstream_check_add_peer(cf, us,
+                                                         &server[i].addrs[0]);
+                } else {
+                    peer[n].check_index = (ngx_uint_t) NGX_ERROR;
+                }
+#endif
+
 #if (NGX_HTTP_UPSTREAM_SID)
                 if (ngx_http_upstream_create_sid(cf, &peer[n], &server[i].sid)
                     != NGX_OK)
@@ -225,6 +239,16 @@
                 peer[n].down = server[i].down;
                 peer[n].server = server[i].name;
 
+#if (NGX_HTTP_UPSTREAM_CHECK)
+                if (!server[i].down) {
+                    peer[n].check_index =
+                        ngx_http_upstream_check_add_peer(cf, us,
+                                                         &server[i].addrs[j]);
+                } else {
+                    peer[n].check_index = (ngx_uint_t) NGX_ERROR;
+                }
+#endif
+
 #if (NGX_HTTP_UPSTREAM_SID)
                 if (ngx_http_upstream_create_sid(cf, &peer[n], &server[i].sid)
                     != NGX_OK)
@@ -338,6 +362,16 @@
                 peer[n].down = server[i].down;
                 peer[n].server = server[i].name;
 
+#if (NGX_HTTP_UPSTREAM_CHECK)
+                if (!server[i].down) {
+                    peer[n].check_index =
+                        ngx_http_upstream_check_add_peer(cf, us,
+                                                         &server[i].addrs[0]);
+                } else {
+                    peer[n].check_index = (ngx_uint_t) NGX_ERROR;
+                }
+#endif
+
 #if (NGX_HTTP_UPSTREAM_SID)
                 if (ngx_http_upstream_create_sid(cf, &peer[n], &server[i].sid)
                     != NGX_OK)
@@ -367,6 +401,16 @@
                 peer[n].down = server[i].down;
                 peer[n].server = server[i].name;
 
+#if (NGX_HTTP_UPSTREAM_CHECK)
+                if (!server[i].down) {
+                    peer[n].check_index =
+                        ngx_http_upstream_check_add_peer(cf, us,
+                                                         &server[i].addrs[j]);
+                } else {
+                    peer[n].check_index = (ngx_uint_t) NGX_ERROR;
+                }
+#endif
+
 #if (NGX_HTTP_UPSTREAM_SID)
                 if (ngx_http_upstream_create_sid(cf, &peer[n], &server[i].sid)
                     != NGX_OK)
@@ -442,6 +486,9 @@
         peer[i].max_conns = 0;
         peer[i].max_fails = 1;
         peer[i].fail_timeout = 10;
+#if (NGX_HTTP_UPSTREAM_CHECK)
+        peer[i].check_index = (ngx_uint_t) NGX_ERROR;
+#endif
         *peerp = &peer[i];
         peerp = &peer[i].next;
     }
@@ -624,6 +671,9 @@
         peer[0].max_conns = 0;
         peer[0].max_fails = 1;
         peer[0].fail_timeout = 10;
+#if (NGX_HTTP_UPSTREAM_CHECK)
+        peer[0].check_index = (ngx_uint_t) NGX_ERROR;
+#endif
         peers->peer = peer;
 
     } else {
@@ -658,6 +708,9 @@
             peer[i].max_conns = 0;
             peer[i].max_fails = 1;
             peer[i].fail_timeout = 10;
+#if (NGX_HTTP_UPSTREAM_CHECK)
+            peer[i].check_index = (ngx_uint_t) NGX_ERROR;
+#endif
             *peerp = &peer[i];
             peerp = &peer[i].next;
         }
@@ -733,6 +786,12 @@
             if (peer->max_conns && peer->conns >= peer->max_conns) {
                 goto failed;
             }
+
+#if (NGX_HTTP_UPSTREAM_CHECK)
+            if (ngx_http_upstream_check_peer_down(peer->check_index)) {
+                goto failed;
+            }
+#endif
 #if (NGX_HTTP_UPSTREAM_SID)
         }
 #endif
@@ -870,6 +929,12 @@
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

