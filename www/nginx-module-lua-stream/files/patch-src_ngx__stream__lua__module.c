--- src/ngx_stream_lua_module.c.orig	2026-10-18 16:01:57 UTC
+++ src/ngx_stream_lua_module.c
@@ -948,7 +948,7 @@ ngx_stream_lua_merge_srv_conf(ngx_conf_t *cf, void *pa
     dd("merge srv conf");
 
     sscf = ngx_stream_conf_get_module_srv_conf(cf, ngx_stream_ssl_module);
-#if defined(nginx_version) && nginx_version >= 1025005
+#if !defined (freenginx) && (defined(nginx_version) && nginx_version >= 1025005)
     if (sscf && sscf->ssl.ctx) {
 #else
     if (sscf && sscf->listen) {
