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
 
@@ -166,9 +162,9 @@
 {
 	char	*word;
 	register unsigned char	*p;
-	register long	sum = 0L;
-	register long	xsum = 0L;
-	register long	n;
+	register int	sum = 0;
+	register int	xsum = 0;
+	register int	n;
 	BOOL	chksum_ok = FALSE;
 	
 	while ((n = fgetline(dat_file, linebuf, sizeof(linebuf))) >= 0) {
