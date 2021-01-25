--- dlib/simd/simd4f.h.orig	2021-01-11 12:18:36 UTC
+++ dlib/simd/simd4f.h
@@ -524,6 +524,11 @@ namespace dlib
 
 // ----------------------------------------------------------------------------------------
 
+#if defined(DLIB_HAVE_VSX) && !defined(vec_rsqrt)
+extern inline __vector float __attribute__((always_inline)) vec_rsqrt(const __vector float& a)
+	{ return vec_div((__vector float){1, 1, 1, 1}, vec_sqrt(a)); }
+#endif
+
     inline simd4f reciprocal_sqrt (const simd4f& item)
     {
 #ifdef DLIB_HAVE_SSE2
