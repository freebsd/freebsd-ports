--- chrome/browser/ui/panels/panel_manager.cc.orig	2015-01-14 08:44:01.000000000 +0100
+++ chrome/browser/ui/panels/panel_manager.cc	2015-01-20 19:36:06.959753456 +0100
@@ -138,7 +138,7 @@
 // static
 bool PanelManager::IsPanelStackingEnabled() {
   // Stacked panel mode is not supported in linux-aura.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   return false;
 #else
   return true;
