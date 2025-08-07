--- chrome/browser/ui/tabs/tab_dialog_manager.cc.orig	2025-08-07 06:57:29 UTC
+++ chrome/browser/ui/tabs/tab_dialog_manager.cc
@@ -85,7 +85,7 @@ bool SupportsGlobalScreenCoordinates() {
 }
 
 bool PlatformClipsChildrenToViewport() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
