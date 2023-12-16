--- src/3rdparty/chromium/third_party/blink/renderer/platform/fonts/font_platform_data.cc.orig	2023-08-16 19:50:41 UTC
+++ src/3rdparty/chromium/third_party/blink/renderer/platform/fonts/font_platform_data.cc
@@ -51,7 +51,7 @@ namespace {
 namespace blink {
 namespace {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Getting the system font render style takes a significant amount of time on
 // Linux because looking up fonts using fontconfig can be very slow. We fetch
 // the render style for each font family and text size, while it's very
@@ -164,7 +164,7 @@ FontPlatformData::FontPlatformData(sk_sp<SkTypeface> t
   style_ = WebFontRenderStyle::GetDefault();
 #if !BUILDFLAG(IS_WIN)
   WebFontRenderStyle system_style;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   bool override_font_name_and_size =
       base::FeatureList::IsEnabled(kOptimizeLinuxFonts);
 #else
