--- ui/color/color_id.h.orig	2024-10-27 06:40:35 UTC
+++ ui/color/color_id.h
@@ -622,7 +622,7 @@
   \
   E_CPONLY(kColorCrosSysPositive) \
   E_CPONLY(kColorCrosSysComplementVariant)
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #define PLATFORM_SPECIFIC_COLOR_IDS \
   E_CPONLY(kColorNativeButtonBorder)\
   E_CPONLY(kColorNativeHeaderButtonBorderActive) \
