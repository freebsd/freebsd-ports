--- chrome/browser/ui/views/task_manager_search_bar_view.cc.orig	2026-08-13 07:41:05 UTC
+++ chrome/browser/ui/views/task_manager_search_bar_view.cc
@@ -28,7 +28,7 @@ namespace task_manager {
 namespace {
 
 ui::ColorId GetTextfieldPlaceholderTextColor() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return kColorTaskManagerSearchBarPlaceholderText;
 #else
   return ui::kColorTextfieldForegroundPlaceholder;
