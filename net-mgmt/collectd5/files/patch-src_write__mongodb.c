--- src/write_mongodb.c.orig	2026-07-07 01:39:52 UTC
+++ src/write_mongodb.c
@@ -36,7 +36,7 @@
 #include "utils/common/common.h"
 #include "utils_cache.h"
 
-#include <mongoc.h>
+#include <mongoc/mongoc.h>
 
 struct wm_node_s {
   char name[DATA_MAX_NAME_LEN];
