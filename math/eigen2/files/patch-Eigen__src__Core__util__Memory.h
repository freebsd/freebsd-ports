--- ./Eigen/src/Core/util/Memory.h.orig	2009-05-22 17:41:27.000000000 +0400
+++ ./Eigen/src/Core/util/Memory.h	2009-05-22 23:12:08.000000000 +0400
@@ -27,7 +27,7 @@
 #ifndef EIGEN_MEMORY_H
 #define EIGEN_MEMORY_H
 
-#if defined(__APPLE__) || defined(_WIN64)
+#if defined(__APPLE__) || defined(_WIN64) || defined (__FreeBSD__)
   #define EIGEN_MALLOC_ALREADY_ALIGNED 1
 #else
   #define EIGEN_MALLOC_ALREADY_ALIGNED 0
