--- src/syslog-names.c.orig	Wed Mar  5 12:16:57 2003
+++ src/syslog-names.c	Wed Mar  5 12:34:40 2003
@@ -47,6 +47,7 @@
 #ifdef LOG_AUTHPRIV
 	{ "authpriv", LOG_AUTHPRIV },
 #endif
+	{ "console", LOG_CONSOLE },
 	{ "cron", LOG_CRON },
 	{ "daemon", LOG_DAEMON },
 #ifdef LOG_FTP
@@ -56,7 +57,8 @@
 	{ "lpr", LOG_LPR },
 	{ "mail", LOG_MAIL },
 	{ "news", LOG_NEWS },
-	{ "security", LOG_AUTH },           /* DEPRECATED */
+	{ "ntp", LOG_NTP },
+	{ "security", LOG_SECURITY },
 	{ "syslog", LOG_SYSLOG },
 	{ "user", LOG_USER },
 	{ "uucp", LOG_UUCP },
