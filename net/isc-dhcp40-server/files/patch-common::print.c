--- common/print.c.orig	Fri Feb  8 22:23:19 2002
+++ common/print.c	Mon May  6 22:00:09 2002
@@ -1366,8 +1366,8 @@
 		*s++ = '.';
 	*s++ = 0;
 	if (errorp)
-		log_error (obuf);
+		log_error ("%s", obuf);
 	else
-		log_info (obuf);
+		log_info ("%s", obuf);
 }
 #endif /* NSUPDATE */
