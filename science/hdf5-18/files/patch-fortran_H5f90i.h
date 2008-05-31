--- fortran/src/H5f90i.h.orig	Thu Jul 12 21:26:46 2007
+++ fortran/src/H5f90i.h	Thu Jul 12 21:27:18 2007
@@ -71,7 +71,7 @@
 #endif /*APPLE*/
 
 /* LINUX definitions */
-#if (defined(linux) || defined(__gnu_linux__) || defined(__linux__))
+#if (defined(linux) || defined(__gnu_linux__) || defined(__linux__) || defined(__FreeBSD__))
 
 /* Common definitions */
 typedef char              *_fcd;
