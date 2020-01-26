--- ext/libswscale/gstffmpegscale.c.orig	2019-12-26 12:03:51.446615000 +0100
+++ ext/libswscale/gstffmpegscale.c	2019-12-26 12:04:18.260579000 +0100
@@ -638,7 +638,7 @@ gst_ffmpegscale_set_caps (GstBaseTransform * trans, Gs
   swsflags = (mmx_flags & ORC_TARGET_MMX_MMX ? SWS_CPU_CAPS_MMX : 0)
       | (mmx_flags & ORC_TARGET_MMX_MMXEXT ? SWS_CPU_CAPS_MMX2 : 0)
       | (mmx_flags & ORC_TARGET_MMX_3DNOW ? SWS_CPU_CAPS_3DNOW : 0)
-      | (altivec_flags & ORC_TARGET_ALTIVEC_ALTIVEC ? SWS_CPU_CAPS_ALTIVEC : 0);
+      | (altivec_flags & ORC_TARGET_POWERPC_ALTIVEC ? SWS_CPU_CAPS_ALTIVEC : 0);
 #else
   mmx_flags = 0;
   altivec_flags = 0;
