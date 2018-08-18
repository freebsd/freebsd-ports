--- third_party/blink/renderer/platform/fonts/font_cache.h.orig	2018-07-19 19:26:12.883838000 +0200
+++ third_party/blink/renderer/platform/fonts/font_cache.h	2018-07-19 19:26:49.537827000 +0200
@@ -213,7 +213,7 @@
       const FontDescription&);
 #endif  // defined(OS_ANDROID)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   struct PlatformFallbackFont {
     String name;
     CString filename;
@@ -287,7 +287,7 @@
                                const FontFaceCreationParams&,
                                CString& name);
 
-#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_FUCHSIA)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_BSD)
   static AtomicString GetFamilyNameForCharacter(SkFontMgr*,
                                                 UChar32,
                                                 const FontDescription&,
