--- fakebo.c.orig	Thu Jun  6 18:13:21 2002
+++ fakebo.c	Thu Jun  6 18:13:31 2002
@@ -457,8 +457,8 @@
 {
 	static char msg[] = "Warning: SIGHUP received, but config re-read not yet implemented!\n";
 
-	logprintf(TRUE, msg);
-	syslogprintf(msg);
+	logprintf(TRUE, "%s", msg);
+	syslogprintf("%s", msg);
 }
 
 #endif
