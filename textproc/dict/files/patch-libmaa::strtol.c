--- libmaa/strtol.c.orig	Sat Jan 11 18:40:34 2003
+++ libmaa/strtol.c	Thu Aug 24 21:59:08 1995
@@ -25,7 +25,7 @@
 #include <stdlib.h>
 #include <errno.h>
 
-#ifdef __sparc__
+#if defined(__sparc__) && !defined(__FreeBSD__)
 extern int errno;
 extern int toupper(int);
 #endif
