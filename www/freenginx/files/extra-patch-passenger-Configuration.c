--- ../passenger-6.1.2/src/nginx_module/Configuration.c.orig	2026-03-09 20:02:40.671082000 +0100
+++ ../passenger-6.1.2/src/nginx_module/Configuration.c	2026-03-09 20:07:45.710035000 +0100
@@ -225,7 +225,7 @@ passenger_create_loc_conf(ngx_conf_t *cf)
     conf->upstream_config.send_lowat = NGX_CONF_UNSET_SIZE;
     conf->upstream_config.buffer_size = NGX_CONF_UNSET_SIZE;
     #if NGINX_VERSION_NUM >= 1027000
-        conf->upstream_config.limit_rate = NGX_CONF_UNSET_PTR;
+        conf->upstream_config.limit_rate = NGX_CONF_UNSET_SIZE;
     #elif NGINX_VERSION_NUM >= 1007007
         conf->upstream_config.limit_rate = NGX_CONF_UNSET_SIZE;
     #endif
@@ -468,8 +468,8 @@ passenger_merge_loc_conf(ngx_conf_t *cf, void *parent,
                               16 * 1024);
 
     #if NGINX_VERSION_NUM >= 1027000
-        ngx_conf_merge_ptr_value(conf->upstream_config.limit_rate,
-                                 prev->upstream_config.limit_rate, NULL);
+        ngx_conf_merge_size_value(conf->upstream_config.limit_rate,
+                                 prev->upstream_config.limit_rate, 0);
     #elif NGINX_VERSION_NUM >= 1007007
         ngx_conf_merge_size_value(conf->upstream_config.limit_rate,
                                   prev->upstream_config.limit_rate, 0);
