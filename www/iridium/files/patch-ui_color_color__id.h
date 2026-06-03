--- ui/color/color_id.h.orig	2026-03-24 16:59:08 UTC
+++ ui/color/color_id.h
@@ -662,7 +662,7 @@
   E_CPONLY(kColorCrosSysPositive) \
   E_CPONLY(kColorCrosSysComplementVariant) \
   E_CPONLY(kColorCrosSysInputFieldOnBase)
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #define PLATFORM_SPECIFIC_COLOR_IDS \
   E_CPONLY(kColorNativeBoxFrameBorder)\
   E_CPONLY(kColorNativeHeaderButtonBorderActive) \
