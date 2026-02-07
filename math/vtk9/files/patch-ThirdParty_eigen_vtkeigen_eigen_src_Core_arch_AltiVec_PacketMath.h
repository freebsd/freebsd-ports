--- ThirdParty/eigen/vtkeigen/eigen/src/Core/arch/AltiVec/PacketMath.h.orig	2021-08-18 20:41:58 UTC
+++ ThirdParty/eigen/vtkeigen/eigen/src/Core/arch/AltiVec/PacketMath.h
@@ -175,16 +175,19 @@ struct packet_traits<float> : default_packet_traits {
 #else
     HasRsqrt = 0,
 #endif
+    HasTanh = EIGEN_FAST_MATH,
+    HasErf = EIGEN_FAST_MATH,
+    HasRint = 1,
 #else
     HasSqrt = 0,
     HasRsqrt = 0,
-    HasTanh = EIGEN_FAST_MATH,
-    HasErf = EIGEN_FAST_MATH,
+    HasTanh = 0,
+    HasErf = 0,
+    HasRint = 0,
 #endif
     HasRound = 1,
     HasFloor = 1,
     HasCeil = 1,
-    HasRint = 1,
     HasNegate = 1,
     HasBlend = 1
   };
@@ -217,16 +220,17 @@ struct packet_traits<bfloat16> : default_packet_traits
 #else
     HasRsqrt = 0,
 #endif
+    HasRint = 1,
 #else
     HasSqrt = 0,
     HasRsqrt = 0,
-    HasTanh = EIGEN_FAST_MATH,
-    HasErf = EIGEN_FAST_MATH,
+    HasRint = 0,
 #endif
+    HasTanh = 0,
+    HasErf = 0,
     HasRound = 1,
     HasFloor = 1,
     HasCeil = 1,
-    HasRint = 1,
     HasNegate = 1,
     HasBlend = 1
   };
@@ -872,19 +876,29 @@ template<> EIGEN_STRONG_INLINE Packet4f pcmp_lt_or_nan
   return vec_nor(c,c);
 }
 
+#ifdef __VSX__
 template<> EIGEN_STRONG_INLINE Packet4i pcmp_le(const Packet4i& a, const Packet4i& b) { return reinterpret_cast<Packet4i>(vec_cmple(a,b)); }
+#endif
 template<> EIGEN_STRONG_INLINE Packet4i pcmp_lt(const Packet4i& a, const Packet4i& b) { return reinterpret_cast<Packet4i>(vec_cmplt(a,b)); }
 template<> EIGEN_STRONG_INLINE Packet4i pcmp_eq(const Packet4i& a, const Packet4i& b) { return reinterpret_cast<Packet4i>(vec_cmpeq(a,b)); }
+#ifdef __VSX__
 template<> EIGEN_STRONG_INLINE Packet8s pcmp_le(const Packet8s& a, const Packet8s& b) { return reinterpret_cast<Packet8s>(vec_cmple(a,b)); }
+#endif
 template<> EIGEN_STRONG_INLINE Packet8s pcmp_lt(const Packet8s& a, const Packet8s& b) { return reinterpret_cast<Packet8s>(vec_cmplt(a,b)); }
 template<> EIGEN_STRONG_INLINE Packet8s pcmp_eq(const Packet8s& a, const Packet8s& b) { return reinterpret_cast<Packet8s>(vec_cmpeq(a,b)); }
+#ifdef __VSX__
 template<> EIGEN_STRONG_INLINE Packet8us pcmp_le(const Packet8us& a, const Packet8us& b) { return reinterpret_cast<Packet8us>(vec_cmple(a,b)); }
+#endif
 template<> EIGEN_STRONG_INLINE Packet8us pcmp_lt(const Packet8us& a, const Packet8us& b) { return reinterpret_cast<Packet8us>(vec_cmplt(a,b)); }
 template<> EIGEN_STRONG_INLINE Packet8us pcmp_eq(const Packet8us& a, const Packet8us& b) { return reinterpret_cast<Packet8us>(vec_cmpeq(a,b)); }
+#ifdef __VSX__
 template<> EIGEN_STRONG_INLINE Packet16c pcmp_le(const Packet16c& a, const Packet16c& b) { return reinterpret_cast<Packet16c>(vec_cmple(a,b)); }
+#endif
 template<> EIGEN_STRONG_INLINE Packet16c pcmp_lt(const Packet16c& a, const Packet16c& b) { return reinterpret_cast<Packet16c>(vec_cmplt(a,b)); }
 template<> EIGEN_STRONG_INLINE Packet16c pcmp_eq(const Packet16c& a, const Packet16c& b) { return reinterpret_cast<Packet16c>(vec_cmpeq(a,b)); }
+#ifdef __VSX__
 template<> EIGEN_STRONG_INLINE Packet16uc pcmp_le(const Packet16uc& a, const Packet16uc& b) { return reinterpret_cast<Packet16uc>(vec_cmple(a,b)); }
+#endif
 template<> EIGEN_STRONG_INLINE Packet16uc pcmp_lt(const Packet16uc& a, const Packet16uc& b) { return reinterpret_cast<Packet16uc>(vec_cmplt(a,b)); }
 template<> EIGEN_STRONG_INLINE Packet16uc pcmp_eq(const Packet16uc& a, const Packet16uc& b) { return reinterpret_cast<Packet16uc>(vec_cmpeq(a,b)); }
 
@@ -937,6 +951,7 @@ template<> EIGEN_STRONG_INLINE Packet4f pround<Packet4
 }
 template<> EIGEN_STRONG_INLINE Packet4f pceil<Packet4f>(const  Packet4f& a) { return vec_ceil(a); }
 template<> EIGEN_STRONG_INLINE Packet4f pfloor<Packet4f>(const Packet4f& a) { return vec_floor(a); }
+#ifdef __VSX__
 template<> EIGEN_STRONG_INLINE Packet4f print<Packet4f>(const Packet4f& a)
 {
     Packet4f res;
@@ -947,6 +962,7 @@ template<> EIGEN_STRONG_INLINE Packet4f print<Packet4f
 
     return res;
 }
+#endif
 
 template<typename Packet> EIGEN_STRONG_INLINE Packet ploadu_common(const __UNPACK_TYPE__(Packet)* from)
 {
@@ -1341,12 +1357,6 @@ template<> EIGEN_STRONG_INLINE Packet8bf psub<Packet8b
   BF16_TO_F32_BINARY_OP_WRAPPER(psub<Packet4f>, a, b);
 }
 
-template<> EIGEN_STRONG_INLINE Packet8bf psqrt<Packet8bf> (const Packet8bf& a){
-  BF16_TO_F32_UNARY_OP_WRAPPER(vec_sqrt, a);
-}
-template<> EIGEN_STRONG_INLINE Packet8bf prsqrt<Packet8bf> (const Packet8bf& a){
-  BF16_TO_F32_UNARY_OP_WRAPPER(prsqrt<Packet4f>, a);
-}
 template<> EIGEN_STRONG_INLINE Packet8bf pexp<Packet8bf> (const Packet8bf& a){
   BF16_TO_F32_UNARY_OP_WRAPPER(pexp_float, a);
 }
@@ -1390,9 +1400,11 @@ template<> EIGEN_STRONG_INLINE Packet8bf pceil<Packet8
 template<> EIGEN_STRONG_INLINE Packet8bf pround<Packet8bf> (const Packet8bf& a){
   BF16_TO_F32_UNARY_OP_WRAPPER(pround<Packet4f>, a);
 }
+#ifdef __VSX__
 template<> EIGEN_STRONG_INLINE Packet8bf print<Packet8bf> (const Packet8bf& a){
   BF16_TO_F32_UNARY_OP_WRAPPER(print<Packet4f>, a);
 }
+#endif
 template<> EIGEN_STRONG_INLINE Packet8bf pmadd(const Packet8bf& a, const Packet8bf& b, const Packet8bf& c) {
   Packet4f a_even = Bf16ToF32Even(a);
   Packet4f a_odd = Bf16ToF32Odd(a);
