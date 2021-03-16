--- png/pngpriv.h.orig	2021-03-16 01:04:47 UTC
+++ png/pngpriv.h
@@ -193,11 +193,7 @@
 #endif
 
 #ifndef PNG_POWERPC_VSX_OPT
-#  if defined(__PPC64__) && defined(__ALTIVEC__) && defined(__VSX__)
-#     define PNG_POWERPC_VSX_OPT 2
-#  else
 #     define PNG_POWERPC_VSX_OPT 0
-#  endif
 #endif
 
 #ifndef PNG_INTEL_SSE_OPT
