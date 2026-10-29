--- vendor/libghostty-vt/pkg/simdutf/vendor/simdutf.h.orig	2026-10-29 15:27:26 UTC
+++ vendor/libghostty-vt/pkg/simdutf/vendor/simdutf.h
@@ -172,7 +172,7 @@
 #elif defined(__aarch64__) || defined(_M_ARM64) || defined(_M_ARM64EC)
   #define SIMDUTF_IS_ARM64 1
 #elif defined(__PPC64__) || defined(_M_PPC64)
-  #if defined(__VEC__) && defined(__ALTIVEC__)
+  #if defined(__VEC__) && defined(__ALTIVEC__) && defined(__POWER8_VECTOR__)
     #define SIMDUTF_IS_PPC64 1
   #endif
 #elif defined(__s390__)
