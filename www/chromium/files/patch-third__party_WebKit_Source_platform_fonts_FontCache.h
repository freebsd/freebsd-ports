--- third_party/WebKit/Source/platform/fonts/FontCache.h.orig	2017-06-05 19:03:26 UTC
+++ third_party/WebKit/Source/platform/fonts/FontCache.h
@@ -144,7 +144,7 @@ class PLATFORM_EXPORT FontCache {
 #else
   static const AtomicString& LegacySystemFontFamily();
 #endif
-#if OS(LINUX) || OS(ANDROID)
+#if OS(LINUX) || OS(ANDROID) || OS(FREEBSD)
   static void SetSystemFontFamily(const AtomicString&);
 #endif
 
@@ -259,7 +259,7 @@ class PLATFORM_EXPORT FontCache {
                                    const FontFaceCreationParams&,
                                    CString& name);
 
-#if OS(ANDROID) || OS(LINUX)
+#if OS(ANDROID) || OS(LINUX) || OS(FREEBSD)
   static AtomicString GetFamilyNameForCharacter(SkFontMgr*,
                                                 UChar32,
                                                 const FontDescription&,
