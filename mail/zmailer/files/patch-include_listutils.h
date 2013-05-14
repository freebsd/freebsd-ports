--- include/listutils.h.orig	2007-06-29 01:06:06.000000000 +0200
+++ include/listutils.h	2013-05-14 10:21:40.000000000 +0200
@@ -64,7 +64,7 @@
 
 /* #undef __GNUC__ */
 
-#if defined(__GNUC__) && !defined(PROFILING) && defined(__OPTIMIZE__)
+#if defined(__GNUC__) && !defined(PROFILING) && defined(__OPTIMIZE__) && 0
 
 #ifndef EXTINLINE
 #define EXTINLINE extern __inline__
@@ -166,7 +166,7 @@
 
 #else /* ---- not profiling ---- */
 
-#if defined(__GNUC__) && !defined(PROFILING) && defined(__OPTIMIZE__)
+#if defined(__GNUC__) && !defined(PROFILING) && defined(__OPTIMIZE__) && 0
 
 EXTINLINE conscell *copycell(conscell *X) {
   conscell *tmp = newcell();
