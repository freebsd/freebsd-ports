--- vendor/eigen/Eigen/src/Core/arch/AltiVec/PacketMath.h.orig	2025-02-03 13:42:28 UTC
+++ vendor/eigen/Eigen/src/Core/arch/AltiVec/PacketMath.h	2026-09-02 17:05:45 UTC
@@ -1340,9 +1340,11 @@
 template<> EIGEN_STRONG_INLINE Packet8bf psub<Packet8bf>(const Packet8bf& a, const Packet8bf& b) {
   BF16_TO_F32_BINARY_OP_WRAPPER(psub<Packet4f>, a, b);
 }
+
+template<> Packet4f psqrt<Packet4f>(const Packet4f& x);
 
 template<> EIGEN_STRONG_INLINE Packet8bf psqrt<Packet8bf> (const Packet8bf& a){
-  BF16_TO_F32_UNARY_OP_WRAPPER(vec_sqrt, a);
+  BF16_TO_F32_UNARY_OP_WRAPPER(psqrt<Packet4f>, a);
 }
 template<> EIGEN_STRONG_INLINE Packet8bf prsqrt<Packet8bf> (const Packet8bf& a){
   BF16_TO_F32_UNARY_OP_WRAPPER(prsqrt<Packet4f>, a);
