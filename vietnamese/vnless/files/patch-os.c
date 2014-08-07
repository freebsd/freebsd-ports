--- os.c.orig	Mon Feb 24 12:45:40 1992
+++ os.c	Wed Dec  4 02:36:59 1996
@@ -13,6 +13,7 @@
 #include <stdio.h>
 #include <signal.h>
 #include <setjmp.h>
+#include <time.h>
 #include "less.h"
 
 char *getenv();
@@ -153,7 +154,7 @@
 	public long
 get_time()
 {
-	long t;
+	time_t t;
 
 	time(&t);
 	return (t);
@@ -294,9 +295,13 @@
 
 #if PERROR
 
+#ifdef USE_FBSD_STD_HDRS
 extern char *sys_errlist[];
 extern int sys_nerr;
 extern int errno;
+#else
+#include <errno.h>
+#endif
 
 	public char *
 errno_message(filename, message, len)
