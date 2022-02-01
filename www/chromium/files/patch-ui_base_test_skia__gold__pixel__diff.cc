--- ui/base/test/skia_gold_pixel_diff.cc.orig	2021-12-14 11:45:39 UTC
+++ ui/base/test/skia_gold_pixel_diff.cc
@@ -146,7 +146,7 @@ std::string SkiaGoldPixelDiff::GetPlatform() {
   return "macOS";
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   return "linux";
 #endif
 }
