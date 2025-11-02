--- ../lua-nginx-module-0.10.29/src/ngx_http_lua_subrequest.c.orig	2025-11-01 23:46:33.237622000 -0400
+++ ../lua-nginx-module-0.10.29/src/ngx_http_lua_subrequest.c	2025-11-01 23:52:42.602198000 -0400
@@ -1373,7 +1373,9 @@
     ngx_str_t *uri, ngx_str_t *args, ngx_http_request_t **psr,
     ngx_http_post_subrequest_t *ps, ngx_uint_t flags)
 {
+#if !defined freenginx
     ngx_time_t                    *tp;
+#endif
     ngx_connection_t              *c;
     ngx_http_request_t            *sr;
     ngx_http_core_srv_conf_t      *cscf;
@@ -1501,9 +1503,13 @@
     sr->subrequests = r->subrequests - 1;
 #endif
 
+#if defined freenginx
+    sr->start_time = ngx_current_msec;
+#else
     tp = ngx_timeofday();
     sr->start_sec = tp->sec;
     sr->start_msec = tp->msec;
+#endif
 
     r->main->count++;
 
