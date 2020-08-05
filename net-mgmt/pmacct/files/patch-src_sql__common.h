--- src/sql_common.h.orig	2020-02-22 20:28:47 UTC
+++ src/sql_common.h
@@ -64,7 +64,7 @@
 #define SQL_TABLE_VERSION_BGP   1000
 
 /* macros */
-#define SPACELEFT(x) (sizeof(x)-strlen(x))
+#define SPACELEFT(x) (sizeof(x)-strlen(x)-1)
 #define SPACELEFT_LEN(x,y) (sizeof(x)-y)
 #define SPACELEFT_PTR(x,y) (y-strlen(x))
 
