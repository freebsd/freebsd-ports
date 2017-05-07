--- src/3rdparty/webkit/Source/WebCore/platform/graphics/filters/arm/FEGaussianBlurNEON.cpp.orig	2017-01-10 15:46:28 UTC
+++ src/3rdparty/webkit/Source/WebCore/platform/graphics/filters/arm/FEGaussianBlurNEON.cpp
@@ -285,7 +285,7 @@ TOSTRING(neonDrawAlphaChannelGaussianBlu
     "vmov.u32 " REMAINING_STRIDES_R ", " REMAINING_STRIDES_S0 NL
     // Early return for 0 strides.
     "cmp " REMAINING_STRIDES_R ", #0" NL
-    "ldmeqia sp!, {r4-r8, r10, r11, pc}" NL
+    "ldmiaeq sp!, {r4-r8, r10, r11, pc}" NL
 
     // Initialize the sum variable.
     "vmov.u32 " SUM_Q ", #0" NL
