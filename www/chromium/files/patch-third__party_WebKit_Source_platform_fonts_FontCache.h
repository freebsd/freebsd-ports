--- third_party/WebKit/Source/platform/fonts/FontCache.h.orig	2017-04-19 19:06:50 UTC
+++ third_party/WebKit/Source/platform/fonts/FontCache.h
@@ -144,7 +144,7 @@ class PLATFORM_EXPORT FontCache {
 #else
   static const AtomicString& legacySystemFontFamily();
 #endif
-#if OS(LINUX) || OS(ANDROID)
+#if OS(LINUX) || OS(ANDROID) || OS(FREEBSD)
   static void setSystemFontFamily(const AtomicString&);
 #endif
 
@@ -258,7 +258,7 @@ class PLATFORM_EXPORT FontCache {
                                    const FontFaceCreationParams&,
                                    CString& name);
 
-#if OS(ANDROID) || OS(LINUX)
+#if OS(ANDROID) || OS(LINUX) || OS(FREEBSD) || OS(OPENBSD)
   static AtomicString getFamilyNameForCharacter(SkFontMgr*,
                                                 UChar32,
                                                 const FontDescription&,
