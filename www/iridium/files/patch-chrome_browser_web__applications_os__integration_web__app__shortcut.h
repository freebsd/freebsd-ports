--- chrome/browser/web_applications/os_integration/web_app_shortcut.h.orig	2023-03-13 07:33:08 UTC
+++ chrome/browser/web_applications/os_integration/web_app_shortcut.h
@@ -20,7 +20,7 @@
 #include "ui/gfx/image/image_family.h"
 #include "url/gurl.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/web_applications/os_integration/web_app_shortcut_linux.h"
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -66,7 +66,7 @@ struct ShortcutInfo {
   std::set<std::string> file_handler_extensions;
   std::set<std::string> file_handler_mime_types;
   std::set<std::string> protocol_handlers;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::set<DesktopActionInfo> actions;
 #endif  // BUILDFLAG(IS_LINUX)
 
