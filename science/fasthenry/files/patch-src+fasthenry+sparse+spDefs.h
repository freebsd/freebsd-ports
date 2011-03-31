--- src/fasthenry/sparse/spDefs.h.orig	2009-01-11 14:25:17.000000000 -0500
+++ src/fasthenry/sparse/spDefs.h	2011-03-31 11:38:42.000000000 -0400
@@ -431,7 +431,7 @@
  */
 
 /*
-extern char *malloc(), *calloc(), *realloc();
+extern void *malloc(), *calloc(), *realloc();
 #ifdef ultrix
     extern void free();
     extern void abort();
