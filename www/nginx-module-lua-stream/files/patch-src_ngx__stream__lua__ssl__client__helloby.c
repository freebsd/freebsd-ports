--- src/ngx_stream_lua_ssl_client_helloby.c.orig	2025-10-24 14:55:36 UTC
+++ src/ngx_stream_lua_ssl_client_helloby.c
@@ -218,7 +218,7 @@ ngx_stream_lua_ssl_client_hello_handler(ngx_ssl_conn_t
         return -1;
     }
 
-#if (nginx_version > 1029001)
+#if (nginx_version > 1029001) && !defined(freenginx)
     /* see commit 0373fe5d98c1515640 for more details */
     rc = ngx_ssl_client_hello_callback(ssl_conn, al, arg);
 
