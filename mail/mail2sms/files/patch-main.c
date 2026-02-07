--- main.c.orig	2002-04-26 20:36:46 UTC
+++ main.c
@@ -18,7 +18,7 @@ extern int maxparts;
 #ifdef AFS
 #define CONFIGDIR "/var/mail2sms/"
 #else
-#define GLOBAL_CONFIG "/etc/mail/sms/mail2sms.conf"
+#define GLOBAL_CONFIG "%%PREFIX%%/etc/mail2sms.conf"
 #endif
 
 extern FILE *logfile; /* write logs to this file pointer */
