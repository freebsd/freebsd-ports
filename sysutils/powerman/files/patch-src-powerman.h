$FreeBSD$

--- src/powerman.h.orig	Thu Jun 10 08:57:15 2004
+++ src/powerman.h	Thu Jun 10 08:57:55 2004
@@ -39,10 +39,10 @@
 #endif                          /* MIN */
 
 #define DAEMON_NAME   		"powermand"
-#define PID_FILE_NAME 		"/var/run/powerman/powerman.pid"
-#define PID_DIR       		"/var/run/powerman"
-#define ROOT_DIR      		"/etc/powerman"
-#define DFLT_CONFIG_FILE 	"/etc/powerman/powerman.conf"
+#define PID_FILE_NAME 		"/var/run/powerman.pid"
+#define PID_DIR       		"/var/run"
+#define ROOT_DIR      		"%%PREFIX%%/etc/powerman"
+#define DFLT_CONFIG_FILE 	"%%PREFIX%%/etc/powerman.conf"
 
 #define DFLT_PORT           "10101"
 #define DFLT_HOSTNAME       "localhost"
