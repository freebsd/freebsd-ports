--- ui/base/test/skia_gold_pixel_diff.cc.orig	2025-02-22 18:06:53 UTC
+++ ui/base/test/skia_gold_pixel_diff.cc
@@ -112,7 +112,7 @@ const char* GetPlatformName() {
   return "windows";
 #elif BUILDFLAG(IS_APPLE)
   return "macOS";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return "linux";
 #elif BUILDFLAG(IS_CHROMEOS)
   return "ash";
