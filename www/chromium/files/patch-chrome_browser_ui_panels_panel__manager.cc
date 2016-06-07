--- chrome/browser/ui/panels/panel_manager.cc.orig	2016-05-11 19:02:16 UTC
+++ chrome/browser/ui/panels/panel_manager.cc
@@ -142,7 +142,7 @@ bool PanelManager::ShouldUsePanels(const
 // static
 bool PanelManager::IsPanelStackingEnabled() {
   // Stacked panel mode is not supported in linux-aura.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   return false;
 #else
   return true;
