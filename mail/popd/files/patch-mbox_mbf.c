--- mbox_mbf.c.orig	Tue Apr 17 05:09:26 2001
+++ mbox_mbf.c	Wed May 16 08:52:34 2001
@@ -178,7 +178,7 @@
 	size_t	left, bytes, len;
 	char	buffer[MAXBUFLEN];
 
-	facility = LOG_NOTICE;
+	facility = LOG_INFO;
 	ret = del = exp = rem = errors = 0;
 	dst = -1;
 	for (i = 0; i <= user->mbx.num; i++) {
