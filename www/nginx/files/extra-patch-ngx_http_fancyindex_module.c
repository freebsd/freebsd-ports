--- ../ngx-fancyindex-0.2.2/ngx_http_fancyindex_module.c.orig	2010-05-24 17:59:08.000000000 +0400
+++ ../ngx-fancyindex-0.2.2/ngx_http_fancyindex_module.c	2010-05-24 17:59:36.000000000 +0400
@@ -591,9 +591,6 @@
     }
 
     /* TODO: Win32 */
-    if (r->zero_in_uri) {
-        return NGX_DECLINED;
-    }
 
     if (!(r->method & (NGX_HTTP_GET|NGX_HTTP_HEAD))) {
         return NGX_DECLINED;
