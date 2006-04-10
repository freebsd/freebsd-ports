--- include/CGAL/number_type_basic.h.orig	Mon Apr 10 07:51:20 2006
+++ include/CGAL/number_type_basic.h	Mon Apr 10 07:51:36 2006
@@ -404,7 +404,9 @@
 // Integer and Double from _QP_solver
 
 CGAL_END_NAMESPACE
+#ifdef CGAL_USE_GMP
 #include <CGAL/_QP_solver/Double.h>
+#endif
 CGAL_BEGIN_NAMESPACE
 
 
