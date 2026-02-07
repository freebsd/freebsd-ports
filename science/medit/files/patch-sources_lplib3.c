--- sources/lplib3.c.orig	2011-03-15 11:22:22.000000000 +0100
+++ sources/lplib3.c	2012-11-22 22:25:15.000000000 +0100
@@ -29,6 +29,10 @@
 #include <stdbool.h>
 #include <assert.h>
 #include <errno.h>
+#ifdef __FreeBSD__
+# include <sys/types.h>
+# include <pmc.h>
+#endif
 #include "lplib3.h"
 
 
@@ -1244,6 +1248,7 @@
 		goto f1;
 	errno = 0;
 #ifdef __FreeBSD__
+	int ncpu;
 	if (maxthreads == 0) {
 		/*
 		 * Other candidates:
