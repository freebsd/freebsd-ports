
$FreeBSD$

--- src/ssl.c.orig	Wed Dec  4 22:40:45 2002
+++ src/ssl.c	Sun Mar  7 15:10:48 2004
@@ -64,7 +64,7 @@
 	if (options.termlevel != SILENT) {
 		#ifdef HAVE_SYSLOG
 		if ((topt & T_DAEMON) && !(topt & T_FOREGROUND))
-			syslog(LOG_ERR | LOG_MAIL, string_error);
+			syslog(LOG_ERR | LOG_MAIL, "%s", string_error);
 		else
 		#endif /* HAVE_SYSLOG */
 			mprintf(">>%s", string_error);
