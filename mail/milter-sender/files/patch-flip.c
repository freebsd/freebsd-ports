--- ../tools/flip.c.orig	Fri Dec 19 23:10:59 2003
+++ ../tools/flip.c	Fri Dec 19 23:11:48 2003
@@ -154,8 +154,7 @@
 	if (fmt == (const char *) 0)
 		fmt = "Terminated for unknown reason.";
 
-	ErrorPrintV(file, line, fmt, args);
-	ErrorPrintV(file, line, "\r\n", (va_list) 0);
+	ErrorPrintLineV(file, line, fmt, args);
 	exit(1);
 }
 
