
$FreeBSD$

--- src/log.c.orig	Wed Dec  4 22:42:26 2002
+++ src/log.c	Sun Mar  7 15:10:48 2004
@@ -70,7 +70,7 @@
 		if (options.slogfile)
 			filelog(options.slogfile, txt);
 		else
-			syslog(LOG_INFO | LOG_MAIL, txt);
+			syslog(LOG_INFO | LOG_MAIL, "%s", txt);
 
 		if (options.ulogfile && options.uloglevel >= ALL)
 			filelog(options.ulogfile, txt);
