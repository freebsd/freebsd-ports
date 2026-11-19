--- ui/base/test/skia_gold_pixel_diff.cc.orig	2026-11-19 12:25:27 UTC
+++ ui/base/test/skia_gold_pixel_diff.cc
@@ -118,7 +118,7 @@ const char* GetPlatformName() {
   return "windows";
 #elif BUILDFLAG(IS_APPLE)
   return "macOS";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return "linux";
 #elif BUILDFLAG(IS_CHROMEOS)
   return "ash";
