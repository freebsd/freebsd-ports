--- src/sql_common.h.orig	2022-12-31 19:17:17 UTC
+++ src/sql_common.h
@@ -63,7 +63,7 @@
 #define SQL_TABLE_VERSION_BGP   1000
 
 /* macros */
-#define SPACELEFT(x) (sizeof(x)-strlen(x))
+#define SPACELEFT(x) (sizeof(x)-strlen(x)-1)
 #define SPACELEFT_LEN(x,y) (sizeof(x)-y)
 #define SPACELEFT_PTR(x,y) (y-strlen(x))
 
