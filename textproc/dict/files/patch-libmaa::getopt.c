--- libmaa/getopt.c.orig	Sat Jan 11 18:40:00 2003
+++ libmaa/getopt.c	Sat Jan 11 18:40:12 2003
@@ -44,7 +44,7 @@
 
 #include <stdio.h>
 
-#ifdef __sparc__
+#if defined(__sparc__) && !defined(__FreeBSD__)
 extern int fprintf( FILE *, const char *, ... );
 extern int strncmp( const char *, const char *, int n );
 #endif
