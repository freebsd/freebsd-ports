-- Fix uninitialized member variable and simplify SSE complex number loading.
-- Initialize Packet2cf::v to zero to avoid undefined behavior. Replace
-- gcc-version-specific workarounds for loading complex floats with portable
-- SSE2/SSE3 intrinsics (via EIGEN_VECTORIZE_SSE3 check).
--- third_party/eigen3/Eigen/src/Core/arch/SSE/Complex.h.orig	2021-03-15 20:32:24 UTC
+++ third_party/eigen3/Eigen/src/Core/arch/SSE/Complex.h
@@ -17,7 +17,7 @@ struct Packet2cf
 //---------- float ----------
 struct Packet2cf
 {
-  EIGEN_STRONG_INLINE Packet2cf() {}
+  EIGEN_STRONG_INLINE Packet2cf() :v(_mm_setzero_ps()) {}
   EIGEN_STRONG_INLINE explicit Packet2cf(const __m128& a) : v(a) {}
   __m128  v;
 };
@@ -113,19 +113,13 @@ template<> EIGEN_STRONG_INLINE Packet2cf pset1<Packet2
 template<> EIGEN_STRONG_INLINE Packet2cf pset1<Packet2cf>(const std::complex<float>&  from)
 {
   Packet2cf res;
-#if EIGEN_GNUC_AT_MOST(4,2)
-  // Workaround annoying "may be used uninitialized in this function" warning with gcc 4.2
-  res.v = _mm_loadl_pi(_mm_set1_ps(0.0f), reinterpret_cast<const __m64*>(&from));
-#elif EIGEN_GNUC_AT_LEAST(4,6)
-  // Suppress annoying "may be used uninitialized in this function" warning with gcc >= 4.6
-  #pragma GCC diagnostic push
-  #pragma GCC diagnostic ignored "-Wuninitialized"
-  res.v = _mm_loadl_pi(res.v, (const __m64*)&from);
-  #pragma GCC diagnostic pop
+#ifdef EIGEN_VECTORIZE_SSE3
+  res.v = _mm_castpd_ps(_mm_loaddup_pd(reinterpret_cast<double const*>(&from)));
 #else
-  res.v = _mm_loadl_pi(res.v, (const __m64*)&from);
+  res.v = _mm_castpd_ps(_mm_load_sd(reinterpret_cast<double const*>(&from)));
+  res.v = _mm_movelh_ps(res.v, res.v);
 #endif
-  return Packet2cf(_mm_movelh_ps(res.v,res.v));
+  return res;
 }
 
 template<> EIGEN_STRONG_INLINE Packet2cf ploaddup<Packet2cf>(const std::complex<float>* from) { return pset1<Packet2cf>(*from); }
