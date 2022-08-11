--- Source/WebCore/platform/graphics/cpu/arm/filters/FELightingNEON.cpp.orig	2018-05-07 07:58:18 UTC
+++ Source/WebCore/platform/graphics/cpu/arm/filters/FELightingNEON.cpp
@@ -35,7 +35,7 @@ namespace WebCore {
 //   ALPHAX_Q ALPHAY_Q REMAPX_D REMAPY_D
 
 
-static alignas(16) short s_FELightingConstantsForNeon[] = {
+alignas(16) static short s_FELightingConstantsForNeon[] = {
     // Alpha coefficients.
     -2, 1, 0, -1, 2, 1, 0, -1,
     0, -1, -2, -1, 0, 1, 2, 1,
@@ -403,7 +403,7 @@ TOSTRING(neonDrawLighting) ":" NL
     "vmin.f32 " TMP2_D0 ", " TMP2_D0 ", " CONST_ONE_HI_D NL
     "vmul.f32 " TMP3_Q ", " COLOR_Q ", " TMP2_D0 "[1]" NL
     "vcvt.u32.f32 " TMP3_Q ", " TMP3_Q NL
-    "vmov.u32 r2, r3, " TMP3_S0 ", " TMP3_S1 NL
+    "vmov r2, r3, " TMP3_S0 ", " TMP3_S1 NL
     // The color values are stored in-place.
     "strb r2, [" PIXELS_R ", #-11]" NL
     "strb r3, [" PIXELS_R ", #-10]" NL
