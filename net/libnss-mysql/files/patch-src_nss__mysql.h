--- src/nss_mysql.h.orig	2005-09-04 03:34:02 UTC
+++ src/nss_mysql.h
@@ -72,6 +72,10 @@ typedef nss_status_t NSS_STATUS;
 /* Default initializers */
 #define DEF_TIMEOUT         3
 
+#if !defined(MARIADB_BASE_VERSION) && MYSQL_VERSION_ID >= 80001
+#define my_bool bool
+#endif
+
 #ifdef DEBUG
 void _nss_mysql_debug (char *fmt, ...);
 #define DEBUG_FILE "/tmp/libnss-mysql-debug.log"
