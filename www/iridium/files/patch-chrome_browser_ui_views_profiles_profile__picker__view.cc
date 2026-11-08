--- chrome/browser/ui/views/profiles/profile_picker_view.cc.orig	2026-08-13 16:48:13 UTC
+++ chrome/browser/ui/views/profiles/profile_picker_view.cc
@@ -87,7 +87,7 @@
 #include "chrome/browser/global_keyboard_shortcuts_mac.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/shell_integration_linux.h"
 #endif
 
