--- ../lua-nginx-module-0.10.8/src/ngx_http_lua_headers.h.orig	2017-04-15 11:05:40.649209000 -0400
+++ ../lua-nginx-module-0.10.8/src/ngx_http_lua_headers.h	2017-04-15 11:06:01.658936000 -0400
@@ -15,6 +15,9 @@
 void ngx_http_lua_inject_resp_header_api(lua_State *L);
 void ngx_http_lua_inject_req_header_api(lua_State *L);
 void ngx_http_lua_create_headers_metatable(ngx_log_t *log, lua_State *L);
+#if nginx_version >= 1011011
+void ngx_http_lua_ngx_raw_header_cleanup(void *data);
+#endif
 
 
 #endif /* _NGX_HTTP_LUA_HEADERS_H_INCLUDED_ */
