--- packages/external/ampl/fpinit.c.orig	2021-10-21 13:10:57 UTC
+++ packages/external/ampl/fpinit.c
@@ -214,7 +214,7 @@ fpinit_ASL(Void)
 
 /* Currently, FP_PD is the default on FreeBSD, but enabled traps */
 /* can cause surprises, so we restore the default IEEE mask. */
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) && (defined (__amd64__) || defined(__i386__))
 #include "floatingpoint.h"
 #define FP_INIT_DONE
  void
