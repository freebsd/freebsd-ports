--- include/defaults.h.orig	Sun Oct  5 02:31:17 2003
+++ include/defaults.h	Sun Dec 14 16:29:00 2003
@@ -49,9 +49,9 @@
 #define DPATH   IRCD_PREFIX                                                     
 #define BINPATH IRCD_PREFIX "/bin/"
 #define MSGPATH IRCD_PREFIX "/messages/"
-#define ETCPATH IRCD_PREFIX "/etc"
-#define LOGPATH IRCD_PREFIX "/logs"
-#define MODPATH IRCD_PREFIX "/modules/"
+#define ETCPATH IRCD_PREFIX "/etc/ircd-hybrid-ru"
+#define LOGPATH             "/var/log/ircd-hybrid-ru"
+#define MODPATH IRCD_PREFIX "/lib/ircd-hybrid-ru-modules/"
 
 /* files */
 #define SPATH   BINPATH "/ircd"                 /* ircd executable */
