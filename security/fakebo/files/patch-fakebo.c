--- fakebo.c.orig	2002-03-28 03:45:29 UTC
+++ fakebo.c
@@ -462,8 +462,8 @@ static void conf_reread(int signo)
 {
 	static char msg[] = "Warning: SIGHUP received, but config re-read not yet implemented!\n";
 
-	logprintf(TRUE, msg);
-	syslogprintf(msg);
+	logprintf(TRUE, "%s", msg);
+	syslogprintf("%s", msg);
 }
 
 #endif
