--- src/syslog-names.c.orig	Wed Feb 28 10:19:12 2007
+++ src/syslog-names.c	Wed Aug 22 15:48:07 2007
@@ -45,6 +45,7 @@
 #ifdef LOG_AUTHPRIV
   {"authpriv", LOG_AUTHPRIV},
 #endif
+  {"console", LOG_CONSOLE },
 #ifdef LOG_CRON
   {"cron", LOG_CRON},
 #endif
@@ -56,7 +57,8 @@
   {"lpr", LOG_LPR},
   {"mail", LOG_MAIL},
   {"news", LOG_NEWS},
-  {"security", LOG_AUTH},	/* DEPRECATED */
+  {"ntp", LOG_NTP },
+  {"security", LOG_SECURITY },
   {"syslog", LOG_SYSLOG},
   {"user", LOG_USER},
   {"uucp", LOG_UUCP},
