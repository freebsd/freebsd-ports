--- chrome/browser/ui/tabs/tab_dialog_manager.cc.orig	2025-12-06 13:30:52 UTC
+++ chrome/browser/ui/tabs/tab_dialog_manager.cc
@@ -90,7 +90,7 @@ bool SupportsGlobalScreenCoordinates() {
 }
 
 bool PlatformClipsChildrenToViewport() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
