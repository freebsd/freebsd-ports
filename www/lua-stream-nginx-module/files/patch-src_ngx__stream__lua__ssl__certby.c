--- src/ngx_stream_lua_ssl_certby.c.orig
+++ src/ngx_stream_lua_ssl_certby.c
@@ -1554,7 +1554,7 @@ ngx_stream_lua_ffi_ssl_verify_client(ngx
 
     ngx_stream_lua_ctx_t        *ctx;
     ngx_ssl_conn_t              *ssl_conn;
-#if defined(nginx_version) && nginx_version >= 1025005
+#if defined(nginx_version) && nginx_version >= 1025005 && !defined(freenginx)
     ngx_stream_ssl_srv_conf_t   *sscf;
 #else
     ngx_stream_ssl_conf_t       *sscf;
