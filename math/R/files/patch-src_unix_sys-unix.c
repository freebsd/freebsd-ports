--- src/unix/sys-unix.c.orig	2021-03-28 00:59:38 UTC
+++ src/unix/sys-unix.c
@@ -909,12 +909,6 @@ void R_ProcessEvents(void)
  *  helpers for start-up code
  */
 
-#ifdef __FreeBSD__
-# ifdef HAVE_FLOATINGPOINT_H
-#  include <floatingpoint.h>
-# endif
-#endif
-
 /* patch from Ei-ji Nakama for Intel compilers on ix86.
    From http://www.nakama.ne.jp/memo/ia32_linux/R-2.1.1.iccftzdaz.patch.txt.
    Since updated to include x86_64.
@@ -928,9 +922,6 @@ void R_ProcessEvents(void)
 void fpu_setup(Rboolean start)
 {
     if (start) {
-#ifdef __FreeBSD__
-    fpsetmask(0);
-#endif
 
 #if (defined(__i386) || defined(__x86_64)) && defined(__INTEL_COMPILER) && __INTEL_COMPILER > 800
     _MM_SET_FLUSH_ZERO_MODE(_MM_FLUSH_ZERO_OFF);
@@ -953,8 +944,5 @@ void fpu_setup(Rboolean start)
     asm volatile("msr fpcr, %0" : : "r"(fpcr));
 #endif
     } else {
-#ifdef __FreeBSD__
-    fpsetmask(~0);
-#endif
     }
 }
