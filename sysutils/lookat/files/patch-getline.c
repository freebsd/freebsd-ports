--- getline.c.orig	2013-01-04 16:25:54.000000000 +0100
+++ getline.c	2013-01-04 16:37:47.000000000 +0100
@@ -33,7 +33,7 @@
 #include <stdio.h>
 #include <sys/types.h>
 
-#if defined __GNU_LIBRARY__ && HAVE_GETDELIM
+#if HAVE_GETDELIM
 
 #ifndef HAVE_GETLINE
 
@@ -50,15 +50,6 @@
 
 #else /* ! have getdelim */
 
-#if defined(__FreeBSD__)
-#include <osreldate.h>
-#if __FreeBSD_version <= 800066
-int getdelim (lineptr, n, delimiter, stream);
-#else
-ssize_t getdelim (lineptr, n, delimiter, stream);
-#endif
-#endif
-
 # include <assert.h>
 
 # if HAVE_STDLIB_H
