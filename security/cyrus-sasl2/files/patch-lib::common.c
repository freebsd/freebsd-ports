--- lib/common.c.orig	Thu Dec  6 18:34:09 2001
+++ lib/common.c	Thu Dec  6 18:34:24 2001
@@ -596,7 +596,7 @@
     }
     
     /* do the syslog call. do not need to call openlog */
-    syslog(syslog_priority | LOG_AUTH, message);
+    syslog(syslog_priority | LOG_AUTH, "%s", message);
     
     return SASL_OK;
 }
