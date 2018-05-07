--- mod_memcache_block.c.orig	2018-05-08 02:01:33.125306000 +0800
+++ mod_memcache_block.c	2018-05-08 02:02:06.796426000 +0800
@@ -369,6 +369,7 @@
   if (s2conf->response_limiter != NULL) {
     merged_config->response_limiter = apr_hash_copy(p, s2conf->response_limiter);
   }
+  return (void*) merged_config;
 }
 
 static apr_status_t mb_child_exit(void *data)
@@ -416,6 +417,7 @@
   /* finally, refresh the blocklist */
   mb_refresh_blocklist(s);
 
+  return OK;
 }
 
 /* callback used when we walk the array */
