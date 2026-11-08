--- external/gsEigen/src/Core/arch/AltiVec/MathFunctions.h.orig	2025-07-13 16:57:05 UTC
+++ external/gsEigen/src/Core/arch/AltiVec/MathFunctions.h	2026-09-02 17:05:45 UTC
@@ -76,6 +76,20 @@
 }
 #endif
 
+#ifndef __VSX__
+template<> EIGEN_DEFINE_FUNCTION_ALLOWING_MULTIPLE_DEFINITIONS EIGEN_UNUSED
+Packet4f psqrt<Packet4f>(const Packet4f& x)
+{
+  EIGEN_ALIGN16 float a[4];
+  pstore(a, x);
+  a[0] = numext::sqrt(a[0]);
+  a[1] = numext::sqrt(a[1]);
+  a[2] = numext::sqrt(a[2]);
+  a[3] = numext::sqrt(a[3]);
+  return pload<Packet4f>(a);
+}
+#endif
+
 // Hyperbolic Tangent function.
 template <>
 EIGEN_DEFINE_FUNCTION_ALLOWING_MULTIPLE_DEFINITIONS EIGEN_UNUSED Packet4f
