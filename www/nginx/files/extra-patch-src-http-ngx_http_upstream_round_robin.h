--- src/http/ngx_http_upstream_round_robin.h.orig	2016-01-26 14:39:33 UTC
+++ src/http/ngx_http_upstream_round_robin.h
@@ -31,6 +31,10 @@ typedef struct {
     ngx_uint_t                      max_fails;
     time_t                          fail_timeout;
 
+#if (NGX_HTTP_UPSTREAM_CHECK)
+    ngx_uint_t                      check_index;
+#endif
+
     ngx_uint_t                      down;          /* unsigned  down:1; */
 
 #if (NGX_HTTP_SSL)
