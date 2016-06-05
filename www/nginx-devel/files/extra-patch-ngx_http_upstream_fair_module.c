--- ../nginx_upstream_fair-20090923/ngx_http_upstream_fair_module.c.orig	2009-09-24 01:38:16.000000000 +0800
+++ ../nginx_upstream_fair-20090923/ngx_http_upstream_fair_module.c	2016-03-24 13:56:02.990728000 +0800
@@ -9,6 +9,10 @@
 #include <ngx_core.h>
 #include <ngx_http.h>
 
+#if (NGX_HTTP_UPSTREAM_CHECK)
+#include "ngx_http_upstream_check_module.h"
+#endif
+
 typedef struct {
     ngx_uint_t                          nreq;
     ngx_uint_t                          total_req;
@@ -42,6 +46,10 @@
     ngx_uint_t                          max_fails;
     time_t                              fail_timeout;
 
+#if (NGX_HTTP_UPSTREAM_CHECK)
+    ngx_uint_t                          check_index;
+#endif
+
     time_t                              accessed;
     ngx_uint_t                          down:1;
 
@@ -474,6 +482,15 @@
                 peers->peer[n].fail_timeout = server[i].fail_timeout;
                 peers->peer[n].down = server[i].down;
                 peers->peer[n].weight = server[i].down ? 0 : server[i].weight;
+#if (NGX_HTTP_UPSTREAM_CHECK)
+                if (!server[i].down) {
+                    peers->peer[n].check_index =
+                        ngx_http_upstream_check_add_peer(cf, us, &server[i].addrs[j]);
+                }
+                else {
+                    peers->peer[n].check_index = (ngx_uint_t) NGX_ERROR;
+                }
+#endif
                 n++;
             }
         }
@@ -524,6 +541,15 @@
                 backup->peer[n].max_fails = server[i].max_fails;
                 backup->peer[n].fail_timeout = server[i].fail_timeout;
                 backup->peer[n].down = server[i].down;
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
@@ -580,6 +606,9 @@
         peers->peer[i].weight = 1;
         peers->peer[i].max_fails = 1;
         peers->peer[i].fail_timeout = 10;
+#if (NGX_HTTP_UPSTREAM_CHECK)
+        peers->peer[i].check_index = (ngx_uint_t) NGX_ERROR;
+#endif
     }
 
     us->peer.data = peers;
@@ -721,6 +750,12 @@
     peer = &fp->peers->peer[peer_id];
 
     if (!peer->down) {
+#if (NGX_HTTP_UPSTREAM_CHECK)
+        ngx_log_debug1(NGX_LOG_DEBUG_HTTP, pc->log, 0,
+                       "[upstream_fair] get fair peer, check_index: %ui",
+                       peer->check_index);
+        if (!ngx_http_upstream_check_peer_down(peer->check_index)) {
+#endif
         if (peer->max_fails == 0 || peer->shared->fails < peer->max_fails) {
             return NGX_OK;
         }
@@ -731,6 +766,9 @@
             peer->shared->fails = 0;
             return NGX_OK;
         }
+#if (NGX_HTTP_UPSTREAM_CHECK)
+        }
+#endif
     }
 
     return NGX_BUSY;
