--- ui/base/test/skia_gold_pixel_diff.cc.orig	2022-02-28 16:54:41 UTC
+++ ui/base/test/skia_gold_pixel_diff.cc
@@ -150,7 +150,7 @@ std::string SkiaGoldPixelDiff::GetPlatform() {
   return "macOS";
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   return "linux";
 #endif
 }
