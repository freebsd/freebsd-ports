--- ui/color/color_id.h.orig	2022-06-17 14:20:10 UTC
+++ ui/color/color_id.h
@@ -209,7 +209,7 @@
   E_CPONLY(kColorNativeColor6) \
   E_CPONLY(kColorNativeBaseColor) \
   E_CPONLY(kColorNativeSecondaryColor)
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #define PLATFORM_SPECIFIC_COLOR_IDS \
   E_CPONLY(kColorNativeButtonBackground) \
   E_CPONLY(kColorNativeButtonBackgroundDisabled) \
