--- src/ngx_stream_lua_module.c.orig
+++ src/ngx_stream_lua_module.c
@@ -916,7 +916,7 @@ ngx_stream_lua_merge_srv_conf(ngx_conf_t
     ngx_stream_lua_srv_conf_t       *conf = child;
 
 #if (NGX_STREAM_SSL)
-#if defined(nginx_version) && nginx_version >= 1025005
+#if defined(nginx_version) && nginx_version >= 1025005 && !defined(freenginx)
     ngx_stream_ssl_srv_conf_t       *sscf;
 #else
     ngx_stream_ssl_conf_t           *sscf;
@@ -925,7 +925,7 @@ ngx_stream_lua_merge_srv_conf(ngx_conf_t
     dd("merge srv conf");
 
     sscf = ngx_stream_conf_get_module_srv_conf(cf, ngx_stream_ssl_module);
-#if defined(nginx_version) && nginx_version >= 1025005
+#if defined(nginx_version) && nginx_version >= 1025005 && !defined(freenginx)
     if (sscf && sscf->ssl.ctx) {
 #else
     if (sscf && sscf->listen) {
