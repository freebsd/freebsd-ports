--- plugins/common.h.orig	2016-11-29 08:45:08 UTC
+++ plugins/common.h
@@ -174,6 +174,11 @@
  *
  */
 
+/* MariaDB 10.2 client does not set MYSQL_PORT */
+#ifndef MYSQL_PORT
+#  define MYSQL_PORT 3306
+#endif
+
 enum {
 	OK = 0,
 	ERROR = -1
