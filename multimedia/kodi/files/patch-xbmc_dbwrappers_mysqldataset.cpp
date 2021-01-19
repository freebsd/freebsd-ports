--- xbmc/dbwrappers/mysqldataset.cpp.orig	2021-01-18 00:42:21 UTC
+++ xbmc/dbwrappers/mysqldataset.cpp
@@ -18,10 +18,8 @@
 #include <iostream>
 #include <set>
 #include <string>
-#ifdef HAS_MYSQL
+#if defined(HAS_MYSQL) || defined(HAS_MARIADB)
 #include <mysql/errmsg.h>
-#elif defined(HAS_MARIADB)
-#include <mariadb/errmsg.h>
 #endif
 
 #ifdef TARGET_POSIX
