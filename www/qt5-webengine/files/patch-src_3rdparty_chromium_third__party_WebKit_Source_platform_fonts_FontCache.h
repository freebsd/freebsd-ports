--- src/3rdparty/chromium/third_party/WebKit/Source/platform/fonts/FontCache.h.orig	2017-01-26 00:49:28 UTC
+++ src/3rdparty/chromium/third_party/WebKit/Source/platform/fonts/FontCache.h
@@ -121,7 +121,7 @@ class PLATFORM_EXPORT FontCache {
 #else
   static const AtomicString& legacySystemFontFamily();
 #endif
-#if OS(LINUX) || OS(ANDROID)
+#if OS(LINUX) || OS(ANDROID) || OS(FREEBSD)
   static void setSystemFontFamily(const AtomicString&);
 #endif
 
@@ -231,7 +231,7 @@ class PLATFORM_EXPORT FontCache {
                                    const FontFaceCreationParams&,
                                    CString& name);
 
-#if OS(ANDROID) || OS(LINUX)
+#if OS(ANDROID) || OS(LINUX) || OS(FREEBSD) || OS(OPENBSD)
   static AtomicString getFamilyNameForCharacter(SkFontMgr*,
                                                 UChar32,
                                                 const FontDescription&,
