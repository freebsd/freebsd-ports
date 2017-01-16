--- third_party/WebKit/Source/platform/fonts/FontCache.h.orig	2016-12-13 00:42:58 UTC
+++ third_party/WebKit/Source/platform/fonts/FontCache.h
@@ -217,7 +217,7 @@ class PLATFORM_EXPORT FontCache {
                                    const FontFaceCreationParams&,
                                    CString& name);
 
-#if OS(ANDROID) || OS(LINUX)
+#if OS(ANDROID) || OS(LINUX) || OS(FREEBSD) || OS(OPENBSD)
   static AtomicString getFamilyNameForCharacter(SkFontMgr*,
                                                 UChar32,
                                                 const FontDescription&,
