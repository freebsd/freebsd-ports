--- ../ngx_slowfs_cache-1.4/ngx_http_slowfs_module.c.orig	2010-06-07 17:01:32.000000000 +0400
+++ ../ngx_slowfs_cache-1.4/ngx_http_slowfs_module.c	2010-06-07 17:04:15.000000000 +0400
@@ -809,12 +809,6 @@
         return NGX_DECLINED;
     }
 
-#if defined(nginx_version) && (nginx_version < 8038)
-    if (r->zero_in_uri) {
-        return NGX_DECLINED;
-    }
-#endif
-
     slowcf = ngx_http_get_module_loc_conf(r, ngx_http_slowfs_module);
     if (!slowcf->enabled) {
         return NGX_DECLINED;
