--- third_party/pdfium/xfa/fgas/font/cfx_fontsourceenum_file.cpp.orig	2018-12-15 16:04:31.993078000 +0100
+++ third_party/pdfium/xfa/fgas/font/cfx_fontsourceenum_file.cpp	2018-12-15 16:06:14.341565000 +0100
@@ -14,8 +14,9 @@
 
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
