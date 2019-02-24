--- third_party/blink/renderer/platform/fonts/font_cache.h.orig	2019-01-30 02:18:16.000000000 +0100
+++ third_party/blink/renderer/platform/fonts/font_cache.h	2019-02-02 11:22:47.863990000 +0100
@@ -157,7 +157,7 @@
   sk_sp<SkFontMgr> FontManager() { return font_manager_; }
   static void SetFontManager(sk_sp<SkFontMgr>);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // These are needed for calling QueryRenderStyleForStrike, since
   // gfx::GetFontRenderParams makes distinctions based on DSF.
   static float DeviceScaleFactor() { return device_scale_factor_; }
@@ -218,7 +218,7 @@
       const FontDescription&);
 #endif  // defined(OS_ANDROID)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   struct PlatformFallbackFont {
     String name;
     CString filename;
@@ -230,7 +230,7 @@
   static void GetFontForCharacter(UChar32,
                                   const char* preferred_locale,
                                   PlatformFallbackFont*);
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
   scoped_refptr<SimpleFontData> FontDataFromFontPlatformData(
       const FontPlatformData*,
@@ -291,12 +291,12 @@
                                    const FontFaceCreationParams&,
                                    CString& name);
 
-#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_FUCHSIA)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_BSD)
   static AtomicString GetFamilyNameForCharacter(SkFontMgr*,
                                                 UChar32,
                                                 const FontDescription&,
                                                 FontFallbackPriority);
-#endif  // defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_FUCHSIA)
+#endif  // defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_BSD)
 
   scoped_refptr<SimpleFontData> FallbackOnStandardFontStyle(const FontDescription&,
                                                      UChar32);
@@ -327,7 +327,7 @@
   bool is_test_font_mgr_ = false;
 #endif  // defined(OS_WIN)
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   static float device_scale_factor_;
 #endif
 
