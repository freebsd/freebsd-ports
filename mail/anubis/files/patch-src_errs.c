
$FreeBSD$

--- src/errs.c.orig	Wed Dec  4 22:42:02 2002
+++ src/errs.c	Sun Mar  7 15:10:48 2004
@@ -51,7 +51,7 @@
 			if (options.slogfile)
 				filelog(options.slogfile, txt);
 			else
-				syslog(LOG_ERR | LOG_MAIL, txt);
+				syslog(LOG_ERR | LOG_MAIL, "%s", txt);
 
 			if (options.ulogfile && options.uloglevel >= FAILS)
 				filelog(options.ulogfile, txt);
