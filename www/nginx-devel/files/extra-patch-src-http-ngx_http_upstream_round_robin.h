--- src/http/ngx_http_upstream_round_robin.h.orig	2016-02-24 14:53:24 UTC
+++ src/http/ngx_http_upstream_round_robin.h
@@ -35,6 +35,10 @@ struct ngx_http_upstream_rr_peer_s {
     ngx_uint_t                      max_fails;
     time_t                          fail_timeout;
 
+#if (NGX_HTTP_UPSTREAM_CHECK)
+    ngx_uint_t                      check_index;
+#endif
+
     ngx_uint_t                      down;          /* unsigned  down:1; */
 
 #if (NGX_HTTP_SSL)
