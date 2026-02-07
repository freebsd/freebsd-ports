--- rec.h.orig	Fri Jul 11 22:01:27 1997
+++ rec.h	Tue Nov 18 16:58:49 2003
@@ -15,7 +15,7 @@
 
 struct map {                            /* pool cell descriptor */
 	short           busy;           /* cell busy */
-	short           index;          /* index in lindex */
+	int             index;          /* index in lindex */
 	long            time;           /* time of last access */
 };
 
@@ -37,7 +37,7 @@
 	short           fd;             /* file descriptor */
 	short           bakfd;          /* bak file descriptor */
 	short           tfd;            /* temp file descriptor */
-	short           len;            /* length of file in lines */
+	int             len;            /* length of file in lines */
 	short           broken;         /* there are broken lines */
 } REC;
 
