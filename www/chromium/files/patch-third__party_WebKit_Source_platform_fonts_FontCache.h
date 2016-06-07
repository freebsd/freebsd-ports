--- third_party/WebKit/Source/platform/fonts/FontCache.h.orig	2016-05-27 10:32:12.763971000 -0400
+++ third_party/WebKit/Source/platform/fonts/FontCache.h	2016-05-27 10:32:30.876177000 -0400
@@ -174,7 +174,7 @@
     // Implemented on skia platforms.
     PassRefPtr<SkTypeface> createTypeface(const FontDescription&, const FontFaceCreationParams&, CString& name);
 
-#if OS(ANDROID) || OS(LINUX)
+#if OS(ANDROID) || OS(LINUX) || OS(FREEBSD) || OS(OPENBSD)
     static AtomicString getFamilyNameForCharacter(SkFontMgr*, UChar32, const FontDescription&, FontFallbackPriority);
 #endif
 
