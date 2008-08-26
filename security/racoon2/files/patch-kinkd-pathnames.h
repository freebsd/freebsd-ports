--- kinkd/pathnames.h~	2005-08-04 01:14:54.000000000 +0900
+++ kinkd/pathnames.h	2008-08-26 15:23:53.000000000 +0900
@@ -30,7 +30,7 @@
 
 #define PIDFILE_DIR "/var/run"
 #define CACHE_DIR "/var/run"		/* or "/var/db" */
-#define RACOON2_CONFIG_FILE	RACOON2_CONFIG_DIR "/racoon2.conf"
+#define RACOON2_CONFIG_FILE	RACOON_CONF
 
 #ifdef MAKE_KINK_LIST_FILE
 #define KINK_LIST_FILE		"/var/run/kink-handle.list"
