--- ../nginx-module-vts-c382342/src/ngx_http_vhost_traffic_status_module.c.orig	2025-11-02 09:49:45.010029000 -0500
+++ ../nginx-module-vts-c382342/src/ngx_http_vhost_traffic_status_module.c	2025-11-02 09:56:01.011946000 -0500
@@ -354,7 +354,11 @@
     tp = ngx_timeofday();
 
     ms = (ngx_msec_int_t)
+#if (defined freenginx && nginx_version >= 1029000)
+             (tp->sec * 1000 + tp->msec - r->start_time);
+#else
              ((tp->sec - r->start_sec) * 1000 + (tp->msec - r->start_msec));
+#endif
     return ngx_max(ms, 0);
 }
 
