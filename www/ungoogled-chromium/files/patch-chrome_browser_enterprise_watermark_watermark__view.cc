--- chrome/browser/enterprise/watermark/watermark_view.cc.orig	2024-04-23 07:42:17 UTC
+++ chrome/browser/enterprise/watermark/watermark_view.cc
@@ -33,7 +33,7 @@ const gfx::Font& WatermarkFont() {
       "Segoe UI",
 #elif BUILDFLAG(IS_MAC)
       "SF Pro Text",
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       "Ubuntu",
 #elif BUILDFLAG(IS_CHROMEOS)
       "Google Sans",
@@ -45,7 +45,7 @@ const gfx::Font& WatermarkFont() {
 }
 
 gfx::Font::Weight WatermarkFontWeight() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return gfx::Font::Weight::SEMIBOLD;
 #else
   return gfx::Font::Weight::MEDIUM;
