--- misc.c.orig	Tue Feb  7 06:32:01 1995
+++ misc.c	Wed Jun  5 06:12:43 2002
@@ -108,7 +108,7 @@
 	(void) strcat (buf, "\n");
 #ifdef SYSLOG
 		if (!debug_flag)
-			syslog (LOG_ERR, buf);
+			syslog (LOG_ERR, "%s", buf);
 		else
 #endif
 			(void) fprintf (stderr, "%s: %s", pname, buf);
