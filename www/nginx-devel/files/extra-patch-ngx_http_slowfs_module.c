--- ../ngx_slowfs_cache-1.3/ngx_http_slowfs_module.c.orig	2010-05-24 20:27:47.000000000 +0400
+++ ../ngx_slowfs_cache-1.3/ngx_http_slowfs_module.c	2010-05-24 20:28:04.000000000 +0400
@@ -809,10 +809,6 @@
         return NGX_DECLINED;
     }
 
-    if (r->zero_in_uri) {
-        return NGX_DECLINED;
-    }
-
     slowcf = ngx_http_get_module_loc_conf(r, ngx_http_slowfs_module);
     if (!slowcf->enabled) {
         return NGX_DECLINED;
