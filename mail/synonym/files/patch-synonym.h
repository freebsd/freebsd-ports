--- synonym.h.orig	Mon Oct 25 22:53:09 2004
+++ synonym.h	Thu Nov 17 15:04:36 2005
@@ -56,10 +56,10 @@
 /*
  * Defaults
  */
-#define PIDFILE "/var/run/synonym/synonym.pid"
-#define DEFAULT_SOCKET "local:/var/run/synonym/synonym.sock"
-#define DEFAULT_CONFIG "/etc/synonym.conf"
-#define DEFAULT_USER "mail"
+#define PIDFILE RUNDIR "/synonym.pid"
+#define DEFAULT_SOCKET "local:" RUNDIR "/synonym.sock"
+#define DEFAULT_CONFIG PREFIX "/etc/synonym.conf"
+#define DEFAULT_USER SYNONYM_USER
 #define DEFAULT_LOGLEVEL LOG_ERR
 #define DEFAULT_LOGFACILITY LOG_MAIL
 #define DEFAULT_LOGLEVEL_STRING "LOG_ERR"
