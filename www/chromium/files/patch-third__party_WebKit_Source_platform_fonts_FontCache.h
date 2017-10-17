--- third_party/WebKit/Source/platform/fonts/FontCache.h.orig	2017-09-05 21:05:41.000000000 +0200
+++ third_party/WebKit/Source/platform/fonts/FontCache.h	2017-09-06 21:34:33.301287000 +0200
@@ -165,7 +165,7 @@
 #else
   static const AtomicString& LegacySystemFontFamily();
 #endif
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   static void SetSystemFontFamily(const AtomicString&);
 #endif
 
@@ -282,7 +282,7 @@
                                    const FontFaceCreationParams&,
                                    CString& name);
 
-#if defined(OS_ANDROID) || defined(OS_LINUX)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
   static AtomicString GetFamilyNameForCharacter(SkFontMgr*,
                                                 UChar32,
                                                 const FontDescription&,
