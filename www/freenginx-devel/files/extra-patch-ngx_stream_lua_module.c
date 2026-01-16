--- ../stream-lua-nginx-module-0.0.17R4/src/ngx_stream_lua_module.c.orig	2026-01-16 13:32:48.810091000 -0500
+++ ../stream-lua-nginx-module-0.0.17R4/src/ngx_stream_lua_module.c	2026-01-16 13:34:09.124848000 -0500
@@ -919,7 +919,7 @@
     ngx_stream_lua_srv_conf_t       *conf = child;
 
 #if (NGX_STREAM_SSL)
-#if defined(nginx_version) && nginx_version >= 1025005
+#if !defined (freenginx) && (defined(nginx_version) && nginx_version >= 1025005)
     ngx_stream_ssl_srv_conf_t       *sscf;
 #else
     ngx_stream_ssl_conf_t           *sscf;
