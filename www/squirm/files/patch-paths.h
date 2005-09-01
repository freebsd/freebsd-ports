--- paths.h.org	Tue Aug 30 21:14:48 2005
+++ paths.h	Tue Aug 30 21:15:40 2005
@@ -37,14 +37,14 @@
 
 /*************  Log File Locations (must be writable by **********/
 /*************  the user given in the squid.conf file   **********/
-#define LOG_MATCH PREFIX"/logs/squirm.match"
-#define LOG_FAIL  PREFIX"/logs/squirm.fail"
-#define LOG_ERROR PREFIX"/logs/squirm.error"
-#define LOG_WHERE PREFIX"/logs/squirm.where"
-#define LOG_DEBUG PREFIX"/logs/squirm.debug"
-#define LOG_INFO  PREFIX"/logs/squirm.info"
+#define LOG_MATCH PREFIX"/squirm/logs/squirm.match"
+#define LOG_FAIL  PREFIX"/squirm/logs/squirm.fail"
+#define LOG_ERROR PREFIX"/squirm/logs/squirm.error"
+#define LOG_WHERE PREFIX"/squirm/logs/squirm.where"
+#define LOG_DEBUG PREFIX"/squirm/logs/squirm.debug"
+#define LOG_INFO  PREFIX"/squirm/logs/squirm.info"
 
 /*************  Configuration file locations  ***********/
-#define SQUIRM_CONF PREFIX"/etc/squirm.conf"
+#define SQUIRM_CONF PREFIX"/etc/squirm/squirm.conf"
 
 #endif
