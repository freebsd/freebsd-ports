--- third_party/blink/renderer/platform/fonts/font_cache.h.orig	2021-09-24 04:26:12 UTC
+++ third_party/blink/renderer/platform/fonts/font_cache.h
@@ -58,7 +58,7 @@
 #include "third_party/skia/include/core/SkFontMgr.h"
 #include "third_party/skia/include/core/SkRefCnt.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "ui/gfx/font_fallback_linux.h"
 #endif
 
@@ -177,7 +177,7 @@ class PLATFORM_EXPORT FontCache {
   sk_sp<SkFontMgr> FontManager() { return font_manager_; }
   static void SetFontManager(sk_sp<SkFontMgr>);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // These are needed for calling QueryRenderStyleForStrike, since
   // gfx::GetFontRenderParams makes distinctions based on DSF.
   static float DeviceScaleFactor() { return device_scale_factor_; }
@@ -259,11 +259,11 @@ class PLATFORM_EXPORT FontCache {
       const char* locale_family_name);
 #endif  // defined(OS_ANDROID)
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   static bool GetFontForCharacter(UChar32,
                                   const char* preferred_locale,
                                   gfx::FallbackFontData*);
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
   scoped_refptr<SimpleFontData> FontDataFromFontPlatformData(
       const FontPlatformData*,
@@ -339,13 +339,13 @@ class PLATFORM_EXPORT FontCache {
                                    const FontFaceCreationParams&,
                                    std::string& name);
 
-#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   static AtomicString GetFamilyNameForCharacter(SkFontMgr*,
                                                 UChar32,
                                                 const FontDescription&,
                                                 const char* family_name,
                                                 FontFallbackPriority);
-#endif  // defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
   scoped_refptr<SimpleFontData> FallbackOnStandardFontStyle(
       const FontDescription&,
@@ -385,7 +385,7 @@ class PLATFORM_EXPORT FontCache {
   std::unique_ptr<FallbackFamilyStyleCache> fallback_params_cache_;
 #endif  // defined(OS_WIN)
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   static float device_scale_factor_;
 #endif
 
