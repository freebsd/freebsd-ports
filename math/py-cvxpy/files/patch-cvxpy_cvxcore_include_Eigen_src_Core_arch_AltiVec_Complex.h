--- cvxpy/cvxcore/include/Eigen/src/Core/arch/AltiVec/Complex.h.orig	2021-08-18 20:41:58 UTC
+++ cvxpy/cvxcore/include/Eigen/src/Core/arch/AltiVec/Complex.h
@@ -100,6 +100,7 @@ template<> struct packet_traits<std::complex<float> > 
     HasAbs2   = 0,
     HasMin    = 0,
     HasMax    = 0,
+    HasSqrt   = 1,
 #ifdef __VSX__
     HasBlend  = 1,
 #endif
@@ -320,6 +321,7 @@ template<> struct packet_traits<std::complex<double> >
     HasAbs2   = 0,
     HasMin    = 0,
     HasMax    = 0,
+    HasSqrt   = 1,
     HasSetLinear = 0
   };
 };
