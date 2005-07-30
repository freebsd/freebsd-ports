--- src/nss_mysql.h.orig	Tue Jun 28 16:06:14 2005
+++ src/nss_mysql.h	Tue Jun 28 16:17:30 2005
@@ -70,7 +70,7 @@
 #define MAX_QUERY_ATTEMPTS  3           /* # of query retries */
 
 /* Default initializers */
-#define DEF_TIMEOUT     "3"
+#define DEF_TIMEOUT	3
 
 #ifdef DEBUG
 void _nss_mysql_debug (char *fmt, ...);
