--- libmaa/memtest.c.orig	Sat Jan 11 18:40:21 2003
+++ libmaa/memtest.c	Sat Jan 11 18:40:45 2003
@@ -24,7 +24,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 
-#ifdef __sparc__
+#if defined(__sparc__) && !defined(__FreeBSD__)
 extern int printf( const char *, ... );
 #endif
 
