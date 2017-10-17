--- third_party/pdfium/xfa/fgas/font/cfgas_fontmgr.cpp.orig	2017-09-10 01:31:56.349532000 +0200
+++ third_party/pdfium/xfa/fgas/font/cfgas_fontmgr.cpp	2017-09-10 01:33:41.025478000 +0200
@@ -445,8 +445,8 @@
 
 const char* g_FontFolders[] = {
 #if _FXM_PLATFORM_ == _FXM_PLATFORM_LINUX_
-    "/usr/share/fonts", "/usr/share/X11/fonts/Type1",
-    "/usr/share/X11/fonts/TTF", "/usr/local/share/fonts",
+    "/usr/local/share/fonts/Type1",
+    "/usr/local/share/fonts/TTF", "/usr/local/share/fonts",
 #elif _FXM_PLATFORM_ == _FXM_PLATFORM_APPLE_
     "~/Library/Fonts", "/Library/Fonts", "/System/Library/Fonts",
 #elif _FXM_PLATFORM_ == _FXM_PLATFORM_ANDROID_
