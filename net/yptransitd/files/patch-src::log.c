--- src/log.c.orig	Thu Aug 28 04:39:11 2003
+++ src/log.c	Thu Aug 28 04:39:22 2003
@@ -62,7 +62,7 @@
 	else if (prefs.perr == 1)
 		vfprintf (stderr, fmt, args);
 
-	va_end (ap);
+	va_end (args);
 }
 
 void fatal (const char *fmt, ...)
