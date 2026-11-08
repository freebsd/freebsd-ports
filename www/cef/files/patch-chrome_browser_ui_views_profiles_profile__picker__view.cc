--- chrome/browser/ui/views/profiles/profile_picker_view.cc.orig	2026-08-31 10:59:09 UTC
+++ chrome/browser/ui/views/profiles/profile_picker_view.cc
@@ -89,7 +89,7 @@
 #include "chrome/browser/global_keyboard_shortcuts_mac.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/shell_integration_linux.h"
 #endif
 
