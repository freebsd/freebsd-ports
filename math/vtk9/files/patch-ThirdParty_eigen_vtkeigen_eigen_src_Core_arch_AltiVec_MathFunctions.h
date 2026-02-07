--- ThirdParty/eigen/vtkeigen/eigen/src/Core/arch/AltiVec/MathFunctions.h.orig	2021-08-18 20:41:58 UTC
+++ ThirdParty/eigen/vtkeigen/eigen/src/Core/arch/AltiVec/MathFunctions.h
@@ -40,16 +40,14 @@ Packet4f pcos<Packet4f>(const Packet4f& _x)
   return pcos_float(_x);
 }
 
+#ifdef __VSX__
 #ifndef EIGEN_COMP_CLANG
 template<> EIGEN_DEFINE_FUNCTION_ALLOWING_MULTIPLE_DEFINITIONS EIGEN_UNUSED
 Packet4f prsqrt<Packet4f>(const Packet4f& x)
 {
   return  vec_rsqrt(x);
 }
-#endif
 
-#ifdef __VSX__
-#ifndef EIGEN_COMP_CLANG
 template<> EIGEN_DEFINE_FUNCTION_ALLOWING_MULTIPLE_DEFINITIONS EIGEN_UNUSED
 Packet2d prsqrt<Packet2d>(const Packet2d& x)
 {
@@ -73,6 +71,26 @@ template<> EIGEN_DEFINE_FUNCTION_ALLOWING_MULTIPLE_DEF
 Packet2d pexp<Packet2d>(const Packet2d& _x)
 {
   return pexp_double(_x);
+}
+
+template<> EIGEN_STRONG_INLINE Packet8bf psqrt<Packet8bf> (const Packet8bf& a){
+  BF16_TO_F32_UNARY_OP_WRAPPER(psqrt<Packet4f>, a);
+}
+
+#ifndef EIGEN_COMP_CLANG
+template<> EIGEN_STRONG_INLINE Packet8bf prsqrt<Packet8bf> (const Packet8bf& a){
+  BF16_TO_F32_UNARY_OP_WRAPPER(prsqrt<Packet4f>, a);
+}
+#endif
+#else
+template<> EIGEN_DEFINE_FUNCTION_ALLOWING_MULTIPLE_DEFINITIONS
+Packet4f psqrt<Packet4f>(const Packet4f& x)
+{
+  Packet4f a;
+  for (Index i = 0; i < packet_traits<float>::size; i++) {
+    a[i] = numext::sqrt(x[i]);
+  }
+  return a;
 }
 #endif
 
