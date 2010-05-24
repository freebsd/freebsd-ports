--- ../passenger-2.2.11/ext/nginx/StaticContentHandler.c.orig	2010-05-24 20:19:23.000000000 +0400
+++ ../passenger-2.2.11/ext/nginx/StaticContentHandler.c	2010-05-24 20:20:17.000000000 +0400
@@ -66,10 +66,6 @@
         return NGX_DECLINED;
     }
 
-    if (r->zero_in_uri) {
-        return NGX_DECLINED;
-    }
-
     log = r->connection->log;
 
     ngx_log_debug1(NGX_LOG_DEBUG_HTTP, log, 0,
