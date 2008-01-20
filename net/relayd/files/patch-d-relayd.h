--- relayd/relayd.h.orig	2007-12-21 05:15:43.000000000 +0900
+++ relayd/relayd.h	2008-01-14 10:02:42.803752108 +0900
@@ -20,7 +20,7 @@
 
 #include <sys/tree.h>
 
-#define CONF_FILE		"/etc/relayd.conf"
+#define CONF_FILE		"%%PREFIX%%/etc/relayd.conf"
 #define RELAYD_SOCKET		"/var/run/relayd.sock"
 #define PF_SOCKET		"/dev/pf"
 #define RELAYD_USER		"_relayd"
@@ -56,6 +56,15 @@
 #define PURGE_PROTOS		0x08
 #define PURGE_EVERYTHING	0xff
 
+#define	SIMPLEQ_HEAD		STAILQ_HEAD
+#define	SIMPLEQ_FIRST		STAILQ_FIRST
+#define	SIMPLEQ_REMOVE_HEAD	STAILQ_REMOVE_HEAD
+#define	SIMPLEQ_ENTRY		STAILQ_ENTRY
+#define	SIMPLEQ_INIT		STAILQ_INIT
+#define	SIMPLEQ_EMPTY		STAILQ_EMPTY
+#define	SIMPLEQ_NEXT		STAILQ_NEXT
+#define	SIMPLEQ_INSERT_TAIL	STAILQ_INSERT_TAIL
+
 /* buffer */
 struct buf {
 	TAILQ_ENTRY(buf)	 entry;
