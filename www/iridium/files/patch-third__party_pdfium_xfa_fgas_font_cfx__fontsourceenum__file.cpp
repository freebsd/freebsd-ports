--- third_party/pdfium/xfa/fgas/font/cfx_fontsourceenum_file.cpp.orig	2019-03-11 22:08:03 UTC
+++ third_party/pdfium/xfa/fgas/font/cfx_fontsourceenum_file.cpp
@@ -14,8 +14,9 @@ constexpr char kFolderSeparator = '/';
 
 constexpr const char* g_FontFolders[] = {
 #if _FX_PLATFORM_ == _FX_PLATFORM_LINUX_
-    "/usr/share/fonts", "/usr/share/X11/fonts/Type1",
-    "/usr/share/X11/fonts/TTF", "/usr/local/share/fonts",
+    "/usr/local/share/fonts/Type1",
+    "/usr/local/share/fonts/TTF",
+    "/usr/local/share/fonts",
 #elif _FX_PLATFORM_ == _FX_PLATFORM_APPLE_
     "~/Library/Fonts", "/Library/Fonts", "/System/Library/Fonts",
 #elif _FX_PLATFORM_ == _FX_PLATFORM_ANDROID_
