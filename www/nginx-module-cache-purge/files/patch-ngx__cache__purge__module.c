--- ngx_cache_purge_module.c.orig	2026-05-24 00:15:06 UTC
+++ ngx_cache_purge_module.c
@@ -1782,7 +1782,7 @@ typedef struct {
     ngx_array_t               *headers_source;
     /* FIX (#52): nginx 1.29.4 inserted host_set here -- without this guard
      * every subsequent field is at the wrong offset, causing a segfault. */
-#  if (nginx_version >= 1029004)
+#  if (nginx_version >= 1029004) && !defined(freenginx)
     ngx_uint_t                 host_set;
 #  endif
 #  if (nginx_version < 8040)
