--- xgraph.h.orig	Thu Jul 17 03:40:41 1997
+++ xgraph.h	Fri Dec 10 03:10:48 1999
@@ -5,7 +5,12 @@
 #ifndef _XGRAPH_H_
 #define _XGRAPH_H_
 
+#include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 #include <X11/Xos.h>
+#undef index
+#undef rindex
 #include <X11/Xlib.h>
 #include <X11/Xutil.h>
 #include <X11/cursorfont.h>
@@ -33,20 +38,9 @@
 extern void ho_dialog();	/* Hardcopy dialog         */
 extern void set_X();		/* Initializes X device    */
 
-#if 0
-/* To make lint happy */
-extern char *malloc();
-extern char *realloc();
-extern char *sprintf();
-extern char *strcpy();
-extern char *strcat();
-extern char *rindex();
-extern char *index();
-extern void exit();
-extern void free();
-extern double atof();
+#ifndef MAX
+#define MAX(a,b)	((a) > (b) ? (a) : (b))
+#define MIN(a,b)	((a) < (b) ? (a) : (b))
 #endif
-
-extern void abort();
 
 #endif /* _XGRAPH_H_ */
