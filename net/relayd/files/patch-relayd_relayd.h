--- relayd/relayd.h.orig	2014-08-10 20:08:47 UTC
+++ relayd/relayd.h
@@ -21,6 +21,12 @@
 #ifndef _RELAYD_H
 #define _RELAYD_H
 
+#ifdef IN_MAIN
+#define EXTERN
+#else
+#define EXTERN extern
+#endif
+
 #include <sys/tree.h>
 
 #include <sys/param.h>		/* MAXHOSTNAMELEN */
@@ -34,7 +40,7 @@
 #include <imsg.h>
 
 #ifdef __FreeBSD__
-#define	CONF_FILE		"/usr/local/etc/relayd.conf"
+#define	CONF_FILE		"%%PREFIX%%/etc/relayd.conf"
 #else
 #define CONF_FILE		"/etc/relayd.conf"
 #endif
@@ -867,11 +873,13 @@ struct control_sock {
 };
 TAILQ_HEAD(control_socks, control_sock);
 
-struct {
+struct control_state {
 	struct event	 ev;
 	int		 fd;
-} control_state;
+};
 
+EXTERN struct control_state control_state;
+
 enum blockmodes {
 	BM_NORMAL,
 	BM_NONBLOCK
@@ -978,7 +986,9 @@ enum privsep_procid {
 	PROC_PFE,
 	PROC_CA,
 	PROC_MAX
-} privsep_process;
+};
+
+EXTERN enum privsep_procid privsep_process;
 
 /* Attach the control socket to the following process */
 #define PROC_CONTROL	PROC_PFE
