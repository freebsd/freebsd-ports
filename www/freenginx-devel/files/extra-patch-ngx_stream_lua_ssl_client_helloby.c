--- ../stream-lua-nginx-module-0.0.17R4/src/ngx_stream_lua_ssl_client_helloby.c.orig	2026-01-16 13:46:31.750245000 -0500
+++ ../stream-lua-nginx-module-0.0.17R4/src/ngx_stream_lua_ssl_client_helloby.c	2026-01-16 13:47:46.016380000 -0500
@@ -218,7 +218,7 @@
         return -1;
     }
 
-#if (nginx_version > 1029001)
+#if !(freenginx) && (nginx_version > 1029001)
 #ifdef SSL_CLIENT_HELLO_SUCCESS
     /* see commit 0373fe5d98c1515640 for more details */
     rc = ngx_ssl_client_hello_callback(ssl_conn, al, arg);
