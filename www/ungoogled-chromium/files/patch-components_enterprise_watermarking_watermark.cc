--- components/enterprise/watermarking/watermark.cc.orig	2025-09-10 13:22:16 UTC
+++ components/enterprise/watermarking/watermark.cc
@@ -29,7 +29,7 @@ gfx::Font WatermarkFont(int font_size) {
       "Segoe UI",
 #elif BUILDFLAG(IS_MAC)
       "SF Pro Text",
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       "Ubuntu",
 #elif BUILDFLAG(IS_CHROMEOS)
       "Google Sans",
@@ -40,7 +40,7 @@ gfx::Font WatermarkFont(int font_size) {
 }
 
 gfx::Font::Weight WatermarkFontWeight() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return gfx::Font::Weight::SEMIBOLD;
 #else
   return gfx::Font::Weight::MEDIUM;
