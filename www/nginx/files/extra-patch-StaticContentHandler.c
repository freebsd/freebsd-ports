--- ../passenger-2.2.14/ext/nginx/StaticContentHandler.c.orig	2010-06-04 14:37:15.000000000 +0400
+++ ../passenger-2.2.14/ext/nginx/StaticContentHandler.c	2010-06-07 16:59:47.000000000 +0400
@@ -67,12 +67,6 @@
         return NGX_DECLINED;
     }
 
-    #if NGINX_VERSION_NUM < 8038
-        if (r->zero_in_uri) {
-            return NGX_DECLINED;
-        }
-    #endif
-
     log = r->connection->log;
 
     ngx_log_debug1(NGX_LOG_DEBUG_HTTP, log, 0,
