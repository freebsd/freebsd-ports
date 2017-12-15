armv6/v7:
Use correct UAL syntax for 'vmov rx, ry,...' instruction. 
The '.u32' modifier in not allowed for this operand combination 
by ARM ARM, but gas silently ignores it.

See PR 222612

--- Source/WebCore/platform/graphics/cpu/arm/filters/FELightingNEON.cpp.orig	2017-08-23 05:04:24 UTC
+++ Source/WebCore/platform/graphics/cpu/arm/filters/FELightingNEON.cpp
@@ -403,7 +403,7 @@ TOSTRING(neonDrawLighting) ":" NL
     "vmin.f32 " TMP2_D0 ", " TMP2_D0 ", " CONST_ONE_HI_D NL
     "vmul.f32 " TMP3_Q ", " COLOR_Q ", " TMP2_D0 "[1]" NL
     "vcvt.u32.f32 " TMP3_Q ", " TMP3_Q NL
-    "vmov.u32 r2, r3, " TMP3_S0 ", " TMP3_S1 NL
+    "vmov r2, r3, " TMP3_S0 ", " TMP3_S1 NL
     // The color values are stored in-place.
     "strb r2, [" PIXELS_R ", #-11]" NL
     "strb r3, [" PIXELS_R ", #-10]" NL
