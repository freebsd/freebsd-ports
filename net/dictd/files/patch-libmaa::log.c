--- libmaa/log.c.orig	Sat Jun 22 14:12:51 2002
+++ libmaa/log.c	Sat Jun 22 14:12:56 2002
@@ -245,7 +245,7 @@
 {
    if (logFd >= 0)    close( logFd );
    if (logUserStream != stdout && logUserStream != stderr)
-       fclose( logUserStream );
+       if (logUserStream) fclose( logUserStream );
    if (logSyslog)     closelog();
    if (logFilename)   xfree(logFilename);
    if (logFilenameTmp) xfree(logFilenameTmp);
