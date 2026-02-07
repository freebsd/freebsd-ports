--- src/http/ngx_http_upstream_round_robin.h.orig	2016-10-11 11:03:02.000000000 -0400
+++ src/http/ngx_http_upstream_round_robin.h	2016-10-11 19:56:33.262307000 -0400
@@ -35,6 +35,11 @@
 
     ngx_uint_t                      max_fails;
     time_t                          fail_timeout;
+
+#if (NGX_HTTP_UPSTREAM_CHECK)
+    ngx_uint_t                      check_index;
+#endif
+
     ngx_msec_t                      slow_start;
     ngx_msec_t                      start_time;
 
