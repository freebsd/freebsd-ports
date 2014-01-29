--- source4/heimdal/lib/roken/rkpty.c.orig	2013-11-05 12:05:01.120532069 +0000
+++ source4/heimdal/lib/roken/rkpty.c	2013-11-05 12:05:17.764730404 +0000
@@ -232,7 +232,7 @@
 		errx(1, "timeout waiting for %s (line %u)",
 		     c->str, c->lineno);
 	    else if (alarmset)
-		errx(1, "got a signal %d waiting for %s (line %u)",
+		errx(1, "got a signal %ld waiting for %s (line %u)",
 		     alarmset, c->str, c->lineno);
 	    if (sret <= 0)
 		errx(1, "end command while waiting for %s (line %u)",
