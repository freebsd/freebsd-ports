--- ../stream-lua-nginx-module-0.0.17R4/src/ngx_stream_lua_socket_tcp.c.orig	2026-01-16 13:52:57.596777000 -0500
+++ ../stream-lua-nginx-module-0.0.17R4/src/ngx_stream_lua_socket_tcp.c	2026-01-16 13:58:13.256356000 -0500
@@ -2072,7 +2072,9 @@
     ngx_stream_lua_ctx_t                        *ctx;
     ngx_stream_lua_co_ctx_t                     *coctx;
     ngx_stream_lua_socket_tcp_upstream_t        *u;
+#if !defined (freenginx)
     ngx_stream_ssl_srv_conf_t                   *sscf;
+#endif
 
     /* Lua function arguments: self */
 
@@ -2128,6 +2130,7 @@
         return 1;
     }
 
+#if !defined (freenginx)
     sscf = ngx_stream_get_module_srv_conf(r->session, ngx_stream_ssl_module);
 
     if (sscf == NULL || sscf->ssl.ctx == NULL) {
@@ -2141,6 +2144,7 @@
         lua_pushliteral(L, "failed to create ssl connection");
         return 2;
     }
+#endif
 
     ctx = ngx_stream_lua_get_module_ctx(r, ngx_stream_lua_module);
     if (ctx == NULL) {
