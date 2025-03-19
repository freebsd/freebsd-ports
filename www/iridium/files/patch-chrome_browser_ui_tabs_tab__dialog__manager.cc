--- chrome/browser/ui/tabs/tab_dialog_manager.cc.orig	2025-03-18 16:46:04 UTC
+++ chrome/browser/ui/tabs/tab_dialog_manager.cc
@@ -83,7 +83,7 @@ bool SupportsGlobalScreenCoordinates() {
 }
 
 bool PlatformClipsChildrenToViewport() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
