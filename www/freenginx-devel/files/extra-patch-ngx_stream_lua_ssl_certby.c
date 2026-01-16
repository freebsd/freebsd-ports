--- ../stream-lua-nginx-module-0.0.17R4/src/ngx_stream_lua_ssl_certby.c.orig	2026-01-16 13:50:04.806469000 -0500
+++ ../stream-lua-nginx-module-0.0.17R4/src/ngx_stream_lua_ssl_certby.c	2026-01-16 13:50:39.378314000 -0500
@@ -1560,7 +1560,7 @@
 
     ngx_stream_lua_ctx_t        *ctx;
     ngx_ssl_conn_t              *ssl_conn;
-#if defined(nginx_version) && nginx_version >= 1025005
+#if !defined (freenginx) && (defined(nginx_version) && nginx_version >= 1025005)
     ngx_stream_ssl_srv_conf_t   *sscf;
 #else
     ngx_stream_ssl_conf_t       *sscf;
