--- src/ngx_http_lua_subrequest.c.orig
+++ src/ngx_http_lua_subrequest.c
@@ -1502,8 +1502,13 @@
 #endif
 
     tp = ngx_timeofday();
+#if defined(freenginx)
+    (void) tp;
+    sr->start_time = ngx_current_msec;
+#else
     sr->start_sec = tp->sec;
     sr->start_msec = tp->msec;
+#endif
 
     sr->method_name = r->method_name;
     sr->loc_conf = clcf->loc_conf;
