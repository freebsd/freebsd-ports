--- popauth.c.orig	Tue Aug 12 04:39:27 2003
+++ popauth.c	Tue Aug 12 04:39:31 2003
@@ -97,7 +97,7 @@
 #endif
 	(void) vfprintf(stderr, fmt, ap);
 	(void) fprintf(stderr, "\n");
-	va_end(fmt);
+	va_end(ap);
 	exit(1);
 	/*NOTREACHED*/
 }
