- workaround for https://github.com/aykutbulut/CGL-CONIC/issues/5

--- src/CglConicGD1/CglConicGD1Cut.cpp.orig	2021-05-12 18:05:03 UTC
+++ src/CglConicGD1/CglConicGD1Cut.cpp
@@ -3,6 +3,9 @@
 #include <vector>
 #include <numeric>
 
+#define F77_FUNC(name,NAME) name ## _
+#define F77_FUNC_(name,NAME) name
+
 extern "C" {
   // blas routines
   void F77_FUNC(dcopy,DCOPY)(int*, double*, int*, double*, int*);
