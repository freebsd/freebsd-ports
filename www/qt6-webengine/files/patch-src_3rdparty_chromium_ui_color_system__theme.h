--- src/3rdparty/chromium/ui/color/system_theme.h.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/ui/color/system_theme.h
@@ -15,7 +15,7 @@ enum class SystemTheme {
 enum class SystemTheme {
   // Classic theme, used in the default or users' chosen theme.
   kDefault = 0,
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   kGtk = 1,
   kQt = 2,
   kMaxValue = kQt,
