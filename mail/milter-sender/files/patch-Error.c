--- ../lib/io/Error.c.orig	Fri Dec 19 22:34:10 2003
+++ ../lib/io/Error.c	Fri Dec 19 22:42:34 2003
@@ -110,8 +110,7 @@
 	if (fmt == (const char *) 0)
 		fmt = "Terminated for unknown reason.";
 
-	ErrorPrintV(file, line, fmt, args);
-	ErrorPrintV(file, line, "\r\n", (va_list) 0);
+	ErrorPrintLineV(file, line, fmt, args);
 	exit(1);
 }
 
