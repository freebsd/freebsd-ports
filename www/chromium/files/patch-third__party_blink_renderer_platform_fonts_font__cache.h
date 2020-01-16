--- third_party/blink/renderer/platform/fonts/font_cache.h.orig	2019-12-16 21:51:29 UTC
+++ third_party/blink/renderer/platform/fonts/font_cache.h
@@ -162,7 +162,7 @@ class PLATFORM_EXPORT FontCache {
   sk_sp<SkFontMgr> FontManager() { return font_manager_; }
   static void SetFontManager(sk_sp<SkFontMgr>);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // These are needed for calling QueryRenderStyleForStrike, since
   // gfx::GetFontRenderParams makes distinctions based on DSF.
   static float DeviceScaleFactor() { return device_scale_factor_; }
@@ -237,7 +237,7 @@ class PLATFORM_EXPORT FontCache {
       const FontDescription&);
 #endif  // defined(OS_ANDROID)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   struct PlatformFallbackFont {
     String name;
     std::string filename;
@@ -249,7 +249,7 @@ class PLATFORM_EXPORT FontCache {
   static void GetFontForCharacter(UChar32,
                                   const char* preferred_locale,
                                   PlatformFallbackFont*);
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
   scoped_refptr<SimpleFontData> FontDataFromFontPlatformData(
       const FontPlatformData*,
@@ -321,12 +321,12 @@ class PLATFORM_EXPORT FontCache {
                                    const FontFaceCreationParams&,
                                    std::string& name);
 
-#if defined(OS_ANDROID) || defined(OS_LINUX)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
   static AtomicString GetFamilyNameForCharacter(SkFontMgr*,
                                                 UChar32,
                                                 const FontDescription&,
                                                 FontFallbackPriority);
-#endif  // defined(OS_ANDROID) || defined(OS_LINUX)
+#endif  // defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
 
   scoped_refptr<SimpleFontData> FallbackOnStandardFontStyle(
       const FontDescription&,
@@ -360,7 +360,7 @@ class PLATFORM_EXPORT FontCache {
   std::unique_ptr<FallbackFamilyStyleCache> fallback_params_cache_;
 #endif  // defined(OS_WIN)
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   static float device_scale_factor_;
 #endif
 
