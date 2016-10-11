--- src/write_mongodb.c.orig	2016-09-11 08:10:25 UTC
+++ src/write_mongodb.c
@@ -39,7 +39,7 @@
 #else
 # define MONGO_USE_LONG_LONG_INT 1
 #endif
-#include <mongo.h>
+#include <mongoc.h>
 
 #if (MONGO_MAJOR == 0) && (MONGO_MINOR < 8)
 # define bson_alloc()    bson_create()
