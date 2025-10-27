--- chrome/browser/ui/prefs/prefs_tab_helper.cc.orig	2025-10-21 16:57:35 UTC
+++ chrome/browser/ui/prefs/prefs_tab_helper.cc
@@ -64,7 +64,7 @@
 #endif
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(ENABLE_DESKTOP_ANDROID_EXTENSIONS)
+    BUILDFLAG(ENABLE_DESKTOP_ANDROID_EXTENSIONS) || BUILDFLAG(IS_BSD)
 // If a font name in prefs default values starts with a comma, consider it's a
 // comma-separated font list and resolve it to the first available font.
 #define PREFS_FONT_LIST 1
