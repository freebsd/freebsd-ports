--- ../generic/logtosyslog.c.orig	2013-02-05 13:55:15.000000000 +0100
+++ ../generic/logtosyslog.c	2013-02-05 13:55:39.000000000 +0100
@@ -113,7 +113,7 @@
     /* ----------------------------------------------------------------------
      * gonna call syslogName msg
      * ------------------------------------------------------------------- */
-    syslog((int) (*logToSyslogData), msg);
+    syslog((int) (*logToSyslogData), "%s", msg);
 
     return TCL_OK;
 }
