--- src/error.c.orig	2026-08-28 18:35:11 UTC
+++ src/error.c
@@ -123,7 +123,7 @@ err_doit(int errnoflag, int level, const char *fmt, va
 	strcat(buf, "\n");
 
 	if (daemon_proc) {
-		syslog(level, buf);
+		syslog(level, "%s", buf);
 	} else {
 		fflush(stdout);		/* in case stdout and stderr are the same */
 		if(! quiet_mode)
