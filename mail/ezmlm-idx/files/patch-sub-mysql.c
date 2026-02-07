--- sub-mysql.c.orig	2016-07-03 16:26:00 UTC
+++ sub-mysql.c
@@ -6,7 +6,7 @@
 #include "subdb.h"
 #include <sys/types.h>
 #include <mysql.h>
-#include <mysql/errmsg.h>
+#include <errmsg.h>
 #include <mysqld_error.h>
 
 static stralloc line = {0};
