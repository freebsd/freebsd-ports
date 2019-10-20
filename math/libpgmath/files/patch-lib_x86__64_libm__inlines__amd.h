--- lib/x86_64/libm_inlines_amd.h.orig	2019-10-20 13:59:45 UTC
+++ lib/x86_64/libm_inlines_amd.h
@@ -283,7 +283,7 @@ raise_fpsw_flags(int flags)
 {
 #if defined(DONOTDEFINE_WINDOWS)
   _mm_setcsr(_mm_getcsr() | flags);
-#elif defined(linux)
+#elif defined(linux) || defined(__FreeBSD__)
   unsigned int cw;
   /* Get the current floating-point control/status word */
   asm volatile("STMXCSR %0" : "=m"(cw));
