Taken from: [FDclone-users:00142]

--- dosemu.c.orig	Tue Apr 15 00:00:00 2003
+++ dosemu.c	Sat Apr 19 21:07:17 2003
@@ -581,7 +581,7 @@
 #else
 	path = lbuf;
 #endif
-	strncpy(buf, path, bufsiz);
+	for (len = 0; len < bufsiz && path[len]; len++) buf[len] = path[len];
 	return(len);
 }
 
