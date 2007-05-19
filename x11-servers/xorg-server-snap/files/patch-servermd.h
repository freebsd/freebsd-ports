--- include/servermd.h.orig	Sun Jan  8 14:05:55 2006
+++ include/servermd.h	Sun Jan  8 14:06:22 2006
@@ -216,7 +216,7 @@
     defined(__sparc__) || defined(__mc68000__)
 
 #if defined(__sparc) || defined(__sparc__)
-# if !defined(sparc)
+# if !defined(sparc) && !defined(__FreeBSD__)
 #  define sparc 1
 # endif
 #endif
