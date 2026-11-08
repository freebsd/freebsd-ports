--- third_party/blink/renderer/platform/fonts/font_cache.h.orig	2026-10-18 13:29:39 UTC
+++ third_party/blink/renderer/platform/fonts/font_cache.h
@@ -56,7 +56,7 @@
 #include "third_party/skia/include/core/SkRefCnt.h"
 #include "third_party/skia/include/core/SkTypeface.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "ui/gfx/font_fallback_linux.h"
 #endif
 
@@ -150,7 +150,7 @@ class PLATFORM_EXPORT FontCache final {
 
   static void MaybePreloadSystemFonts();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // These are needed for calling QueryRenderStyleForStrike, since
   // gfx::GetFontRenderParams makes distinctions based on DSF.
   static float DeviceScaleFactor() { return device_scale_factor_; }
@@ -228,7 +228,7 @@ class PLATFORM_EXPORT FontCache final {
       const char* locale_family_name);
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   static bool GetFontForCharacter(UChar32,
                                   const char* preferred_locale,
                                   gfx::FallbackFontData*);
@@ -328,7 +328,7 @@ class PLATFORM_EXPORT FontCache final {
   static int32_t status_font_height_;
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   static float device_scale_factor_;
 #endif
 
