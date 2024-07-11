--- ../passenger-6.0.22/src/nginx_module/Configuration.c.orig	2013-10-26 20:00:00.000000000 -0400
+++ ../passenger-6.0.22/src/nginx_module/Configuration.c	2024-06-04 10:53:52.178855000 -0400
@@ -224,8 +224,10 @@
 
     conf->upstream_config.send_lowat = NGX_CONF_UNSET_SIZE;
     conf->upstream_config.buffer_size = NGX_CONF_UNSET_SIZE;
-    #if NGINX_VERSION_NUM >= 1007007
-        conf->upstream_config.limit_rate = NGX_CONF_UNSET_SIZE;
+    #if NGINX_VERSION_NUM >= 1027000
+        conf->upstream_config.limit_rate = NGX_CONF_UNSET_PTR;
+    #elif NGINX_VERSION_NUM >= 1007007
+        conf->upstream_config.limit_rate = NGX_CONF_UNSET_SiZE;
     #endif
 
     conf->upstream_config.busy_buffers_size_conf = NGX_CONF_UNSET_SIZE;
@@ -465,7 +467,10 @@
                               prev->upstream_config.buffer_size,
                               16 * 1024);
 
-    #if NGINX_VERSION_NUM >= 1007007
+    #if NGINX_VERSION_NUM >= 1027000
+        ngx_conf_merge_ptr_value(conf->upstream_config.limit_rate,
+                                  prev->upstream_config.limit_rate, NULL);
+    #elif NGINX_VERSION_NUM >= 1007007
         ngx_conf_merge_size_value(conf->upstream_config.limit_rate,
                                   prev->upstream_config.limit_rate, 0);
     #endif
