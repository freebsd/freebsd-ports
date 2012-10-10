--- Common/vtkMath.h.orig	2012-05-12 13:59:27.000000000 +0200
+++ Common/vtkMath.h	2012-09-13 09:24:53.000000000 +0200
@@ -1336,6 +1336,7 @@
   return result;
 }
 
+#ifndef __WRAP__
 #if defined(VTK_HAS_ISINF)
 //-----------------------------------------------------------------------------
 inline int vtkMath::IsInf(double x)
@@ -1351,5 +1352,6 @@
   return (isnan(x) ? 1 : 0);
 }
 #endif
+#endif
 
 #endif
