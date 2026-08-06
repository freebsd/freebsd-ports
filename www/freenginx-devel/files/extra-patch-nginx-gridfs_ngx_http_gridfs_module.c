--- ../nginx-gridfs-059bdc3/nginx-gridfs/ngx_http_gridfs_module.c.orig	2018-01-20 07:53:32.000000000 +0000
+++ ../nginx-gridfs-059bdc3/nginx-gridfs/ngx_http_gridfs_module.c	2026-07-07 14:27:08.501699000 +0000
@@ -1,7 +1,8 @@
 #include <ngx_config.h>
 #include <ngx_core.h>
 #include <ngx_http.h>
-#include <mongoc.h>
+#include <mongoc/mongoc.h>
+#include <assert.h>
 #include <signal.h>
 #include <stdio.h>
 
@@ -361,7 +361,7 @@
     bson_init(&filter);
     bson_oid_init_from_string(&oid, (const char*)value);
     bson_append_oid(&filter, "_id", -1, &oid);
-    gfile = mongoc_gridfs_find_one(gridfs, &filter, &error);
+    gfile = mongoc_gridfs_find_one_with_opts(gridfs, &filter, NULL, &error);
 
     bson_destroy (&filter);
 
