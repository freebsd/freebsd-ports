--- third_party/blink/renderer/platform/fonts/font_cache.h.orig	2019-10-21 19:06:44 UTC
+++ third_party/blink/renderer/platform/fonts/font_cache.h
@@ -158,7 +158,7 @@ class PLATFORM_EXPORT FontCache {
   sk_sp<SkFontMgr> FontManager() { return font_manager_; }
   static void SetFontManager(sk_sp<SkFontMgr>);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // These are needed for calling QueryRenderStyleForStrike, since
   // gfx::GetFontRenderParams makes distinctions based on DSF.
   static float DeviceScaleFactor() { return device_scale_factor_; }
@@ -233,7 +233,7 @@ class PLATFORM_EXPORT FontCache {
       const FontDescription&);
 #endif  // defined(OS_ANDROID)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   struct PlatformFallbackFont {
     String name;
     std::string filename;
@@ -245,7 +245,7 @@ class PLATFORM_EXPORT FontCache {
   static void GetFontForCharacter(UChar32,
                                   const char* preferred_locale,
                                   PlatformFallbackFont*);
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
   scoped_refptr<SimpleFontData> FontDataFromFontPlatformData(
       const FontPlatformData*,
@@ -317,12 +317,12 @@ class PLATFORM_EXPORT FontCache {
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
@@ -355,7 +355,7 @@ class PLATFORM_EXPORT FontCache {
   mojom::blink::DWriteFontProxyPtr service_;
 #endif  // defined(OS_WIN)
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   static float device_scale_factor_;
 #endif
 
