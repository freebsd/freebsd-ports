--- main.c.orig	Wed Apr 16 05:11:21 2003
+++ main.c	Wed Apr 16 05:12:16 2003
@@ -18,7 +18,7 @@
 #ifdef AFS
 #define CONFIGDIR "/var/mail2sms/"
 #else
-#define GLOBAL_CONFIG "/etc/mail/sms/mail2sms.conf"
+#define GLOBAL_CONFIG "%%PREFIX%%/etc/mail2sms.conf"
 #endif
 
 extern FILE *logfile; /* write logs to this file pointer */
