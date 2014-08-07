--- less.h.orig	1992-02-24 12:45:38.000000000 -0800
+++ less.h	2007-08-23 15:16:23.000000000 -0700
@@ -31,7 +31,11 @@ typedef long		POSITION;
  * The type of signal handler functions.
  * Usually int, although it should be void.
  */
+#if VOID
+typedef	void		HANDLER;
+#else
 typedef	int		HANDLER;
+#endif
 
 
 #define	FILENAME	128	/* Max size of a filename */
@@ -74,7 +78,14 @@ typedef	int		HANDLER;
 #define	SIGNAL(sig,func)	signal(sig,func)
 
 /* Library function declarations */
+#ifdef NO_STD_HDRS
 offset_t lseek();
 char *calloc();
+#else
+#include <stdlib.h>
+#include <unistd.h>
+#include <stdio.h>
+#include <string.h>
+#endif
 
 #include "funcs.h"
