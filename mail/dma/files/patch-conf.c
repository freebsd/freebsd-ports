--- ./conf.c.orig	2012-01-03 13:54:05.000000000 +0000
+++ ./conf.c	2012-01-24 22:57:41.000000000 +0000
@@ -121,7 +121,7 @@
 
 		au = calloc(1, sizeof(*au));
 		if (au == NULL)
-			errlog(1, NULL);
+			errlog(1, "calloc failed");
 
 		data = strdup(line);
 		au->login = strsep(&data, "|");
