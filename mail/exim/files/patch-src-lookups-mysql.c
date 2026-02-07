--- src/lookups/mysql.c.orig	2017-03-05 00:21:35.000000000 +0300
+++ src/lookups/mysql.c	2017-08-15 01:12:26.508519000 +0300
@@ -13,6 +13,7 @@
 #include "lf_functions.h"
 
 #include <mysql.h>       /* The system header */
+#include <mysql_version.h>
 
 
 /* Structure and anchor for caching connections. */
