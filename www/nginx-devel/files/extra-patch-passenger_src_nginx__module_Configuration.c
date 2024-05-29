--- ../passenger-6.0.22/src/nginx_module/Configuration.c.orig	2024-05-29 12:56:52.144194000 -0400
+++ ../passenger-6.0.22/src/nginx_module/Configuration.c	2024-05-29 12:58:07.308893000 -0400
@@ -225,7 +225,7 @@
     conf->upstream_config.send_lowat = NGX_CONF_UNSET_SIZE;
     conf->upstream_config.buffer_size = NGX_CONF_UNSET_SIZE;
     #if NGINX_VERSION_NUM >= 1007007
-        conf->upstream_config.limit_rate = NGX_CONF_UNSET_SIZE;
+        conf->upstream_config.limit_rate = NGX_CONF_UNSET_PTR;
     #endif
 
     conf->upstream_config.busy_buffers_size_conf = NGX_CONF_UNSET_SIZE;
