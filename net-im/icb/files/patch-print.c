$NetBSD: patch-ag,v 1.3 1999/11/26 23:18:47 hubertf Exp $

--- icb/print.c.orig	Fri Feb 24 22:20:25 1995
+++ icb/print.c	Sat Nov 27 00:01:04 1999
@@ -5,6 +5,7 @@
 
 #include "icb.h"
 #include "externs.h"
+#include <time.h>
 
 extern FILE *logfp;
 
@@ -17,12 +18,22 @@
 	char printbuf[1024];
 	char *p = printbuf;
 	char *t = s;
+	struct tm *tm, *localtime();
+	char timestamp[9];
 
 	if (continued) {
 		linenumber = 0;
 		continued = 0;
 	}
 
+	/* If requested, prepare timestamp */
+	if (gv.printtime) {
+		gettime();
+		tm = localtime(&curtime);
+		snprintf(timestamp, sizeof(timestamp), "[%02d:%02d] ",
+		 	tm->tm_hour, tm->tm_min);
+	}
+
 	if (flags & PL_SCR) {
 		/* if paging in effect, do paging */
 		if (gv.pagesize && (++linenumber >= gv.pagesize)) {
@@ -35,6 +46,8 @@
 			*p++ = *t++;
 		*p++ = '\r';
 		*p++ = '\n';
+		if (gv.printtime)
+			write(1, timestamp, 8);
 		write(1, printbuf, p - printbuf);
 	}
 
