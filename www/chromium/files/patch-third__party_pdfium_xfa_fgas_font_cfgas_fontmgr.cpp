--- third_party/pdfium/xfa/fgas/font/cfgas_fontmgr.cpp.orig	2017-12-15 02:05:39.000000000 +0100
+++ third_party/pdfium/xfa/fgas/font/cfgas_fontmgr.cpp	2017-12-24 19:04:05.574318000 +0100
@@ -436,8 +436,8 @@
 
 constexpr const char* g_FontFolders[] = {
 #if _FX_PLATFORM_ == _FX_PLATFORM_LINUX_
-    "/usr/share/fonts", "/usr/share/X11/fonts/Type1",
-    "/usr/share/X11/fonts/TTF", "/usr/local/share/fonts",
+    "/usr/local/share/fonts/Type1",
+    "/usr/local/share/fonts/TTF", "/usr/local/share/fonts",
 #elif _FX_PLATFORM_ == _FX_PLATFORM_APPLE_
     "~/Library/Fonts", "/Library/Fonts", "/System/Library/Fonts",
 #elif _FX_PLATFORM_ == _FX_PLATFORM_ANDROID_
