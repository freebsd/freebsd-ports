--- sformat/datio.c.orig	Mon Dec 16 16:04:37 2002
+++ sformat/datio.c	Mon Dec 16 16:05:11 2002
@@ -81,11 +81,7 @@
 
 char	*datpath[] = {
 		"",
-		"/opt/schily/etc/",
-		"/usr/bert/etc/",
-		"/etc/",
-		"/usr/etc/",
-		"/opt/schily/etc/",
+		"%%DATADIR%%/",
 		NULL
 	};
 
