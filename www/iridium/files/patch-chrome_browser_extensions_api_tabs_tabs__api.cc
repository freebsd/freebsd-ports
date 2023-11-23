--- chrome/browser/extensions/api/tabs/tabs_api.cc.orig	2023-11-22 14:00:11 UTC
+++ chrome/browser/extensions/api/tabs/tabs_api.cc
@@ -861,7 +861,7 @@ ExtensionFunction::ResponseAction WindowsCreateFunctio
 // ui::SHOW_STATE_MINIMIZED above, on Linux the window is not created as
 // minimized.
 // TODO(crbug.com/1410400): Remove this workaround when linux is fixed.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // TODO(crbug.com/1410400): Find a fix for wayland as well.
 
 // Must be defined inside IS_LINUX to compile on windows/mac.
