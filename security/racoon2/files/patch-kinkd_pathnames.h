--- kinkd/pathnames.h.orig	2018-08-15 21:36:53.000000000 -0700
+++ kinkd/pathnames.h	2018-12-15 10:53:06.611652000 -0800
@@ -30,7 +30,7 @@
 
 #define PIDFILE_DIR "/var/run"
 #define CACHE_DIR "/var/run"		/* or "/var/db" */
-#define RACOON2_CONFIG_FILE	SYSCONFDIR "/racoon2.conf"
+#define RACOON2_CONFIG_FILE	"SYSCONFDIR/racoon2.conf"
 
 #ifdef MAKE_KINK_LIST_FILE
 #define KINK_LIST_FILE		"/var/run/kink-handle.list"
