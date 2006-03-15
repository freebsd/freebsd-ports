--- src/fasthenry/sparse/spDefs.h.orig	Sat Feb 25 22:50:35 2006
+++ src/fasthenry/sparse/spDefs.h	Sat Feb 25 22:51:00 2006
@@ -462,7 +462,7 @@
  * MEMORY ALLOCATION
  */
 
-extern char *malloc(), *calloc(), *realloc();
+extern void *malloc(), *calloc(), *realloc();
 #ifdef ultrix
     extern void free();
     extern void abort();
