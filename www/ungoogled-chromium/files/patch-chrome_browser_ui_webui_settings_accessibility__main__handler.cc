--- chrome/browser/ui/webui/settings/accessibility_main_handler.cc.orig	2024-03-22 14:16:19 UTC
+++ chrome/browser/ui/webui/settings/accessibility_main_handler.cc
@@ -19,7 +19,7 @@
 #include "content/public/browser/web_contents.h"
 #include "content/public/browser/web_ui.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "ui/accessibility/accessibility_features.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
 
