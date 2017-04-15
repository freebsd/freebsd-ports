--- ../lua-nginx-module-0.10.8/src/ngx_http_lua_module.c.orig	2017-04-15 11:07:10.366543000 -0400
+++ ../lua-nginx-module-0.10.8/src/ngx_http_lua_module.c	2017-04-15 11:08:25.640520000 -0400
@@ -28,6 +28,7 @@
 #include "ngx_http_lua_ssl_certby.h"
 #include "ngx_http_lua_ssl_session_storeby.h"
 #include "ngx_http_lua_ssl_session_fetchby.h"
+#include "ngx_http_lua_headers.h"
 
 
 static void *ngx_http_lua_create_main_conf(ngx_conf_t *cf);
@@ -624,7 +625,7 @@
     volatile ngx_cycle_t       *saved_cycle;
     ngx_http_core_main_conf_t  *cmcf;
     ngx_http_lua_main_conf_t   *lmcf;
-#ifndef NGX_LUA_NO_FFI_API
+#if !defined(NGX_LUA_NO_FFI_API) || nginx_version >= 1011011
     ngx_pool_cleanup_t         *cln;
 #endif
 
@@ -716,6 +717,16 @@
     cln->handler = ngx_http_lua_sema_mm_cleanup;
 #endif
 
+#if nginx_version >= 1011011
+    cln = ngx_pool_cleanup_add(cf->pool, 0);
+    if (cln == NULL) {
+        return NGX_ERROR;
+    }
+
+    cln->data = lmcf;
+    cln->handler = ngx_http_lua_ngx_raw_header_cleanup;
+#endif
+
     if (lmcf->lua == NULL) {
         dd("initializing lua vm");
 
