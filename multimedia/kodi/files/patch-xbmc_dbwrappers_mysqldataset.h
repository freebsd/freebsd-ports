--- xbmc/dbwrappers/mysqldataset.h.orig	2020-10-04 17:37:02 UTC
+++ xbmc/dbwrappers/mysqldataset.h
@@ -10,10 +10,8 @@
 
 #include <stdio.h>
 #include "dataset.h"
-#ifdef HAS_MYSQL
+#if defined(HAS_MYSQL) || defined(HAS_MARIADB)
 #include <mysql/mysql.h>
-#elif defined(HAS_MARIADB)
-#include <mariadb/mysql.h>
 #endif
 
 namespace dbiplus {
