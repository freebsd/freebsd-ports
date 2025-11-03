--- ../passenger-6.0.27/src/nginx_module/Configuration.c.orig	2013-10-26 20:00:00.000000000 -0400
+++ ../passenger-6.0.27/src/nginx_module/Configuration.c	2025-11-02 20:09:05.651562000 -0500
@@ -224,7 +224,7 @@
 
     conf->upstream_config.send_lowat = NGX_CONF_UNSET_SIZE;
     conf->upstream_config.buffer_size = NGX_CONF_UNSET_SIZE;
-    #if NGINX_VERSION_NUM >= 1027000
+    #if NGINX_VERSION_NUM >= 1027000 && !defined freenginx
         conf->upstream_config.limit_rate = NGX_CONF_UNSET_PTR;
     #elif NGINX_VERSION_NUM >= 1007007
         conf->upstream_config.limit_rate = NGX_CONF_UNSET_SIZE;
@@ -467,7 +467,7 @@
                               prev->upstream_config.buffer_size,
                               16 * 1024);
 
-    #if NGINX_VERSION_NUM >= 1027000
+    #if NGINX_VERSION_NUM >= 1027000 && !defined freenginx
         ngx_conf_merge_ptr_value(conf->upstream_config.limit_rate,
                                  prev->upstream_config.limit_rate, NULL);
     #elif NGINX_VERSION_NUM >= 1007007
