--- ext/libpostproc/gstpostproc.c.orig	2019-12-26 12:04:57.025044000 +0100
+++ ext/libpostproc/gstpostproc.c	2019-12-26 12:05:09.539697000 +0100
@@ -299,7 +299,7 @@ change_context (GstPostProc * postproc, gint width, gi
     ppflags = (mmx_flags & ORC_TARGET_MMX_MMX ? PP_CPU_CAPS_MMX : 0)
         | (mmx_flags & ORC_TARGET_MMX_MMXEXT ? PP_CPU_CAPS_MMX2 : 0)
         | (mmx_flags & ORC_TARGET_MMX_3DNOW ? PP_CPU_CAPS_3DNOW : 0)
-        | (altivec_flags & ORC_TARGET_ALTIVEC_ALTIVEC ? PP_CPU_CAPS_ALTIVEC :
+        | (altivec_flags & ORC_TARGET_POWERPC_ALTIVEC ? PP_CPU_CAPS_ALTIVEC :
         0);
 #else
     mmx_flags = 0;
