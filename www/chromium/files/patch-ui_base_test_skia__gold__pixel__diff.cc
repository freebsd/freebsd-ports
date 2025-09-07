--- ui/base/test/skia_gold_pixel_diff.cc.orig	2025-09-06 10:01:20 UTC
+++ ui/base/test/skia_gold_pixel_diff.cc
@@ -121,7 +121,7 @@ const char* GetPlatformName() {
   return "windows";
 #elif BUILDFLAG(IS_APPLE)
   return "macOS";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return "linux";
 #elif BUILDFLAG(IS_CHROMEOS)
   return "ash";
