--- arpadate.c.orig	Sun Dec  8 18:30:13 2002
+++ arpadate.c	Mon Apr  7 01:17:58 2003
@@ -79,7 +79,7 @@
 	time_t now;
 
 	/* RFC822 format string borrowed from GNU shellutils date.c */
-	const char *format = "%a, %_d %b %Y %H:%M:%S %z";
+	const char *format = "%a, %e %b %Y %H:%M:%S %z";
 
 	now = time(NULL);
 
