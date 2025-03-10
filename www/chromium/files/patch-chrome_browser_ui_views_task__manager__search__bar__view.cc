--- chrome/browser/ui/views/task_manager_search_bar_view.cc.orig	2025-02-19 07:43:18 UTC
+++ chrome/browser/ui/views/task_manager_search_bar_view.cc
@@ -27,7 +27,7 @@ TaskManagerSearchBarView::TaskManagerSearchBarView(
     const gfx::Insets& margins,
     Delegate& delegate)
     : delegate_(delegate)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       ,
       textfield_placeholder_color_id_(kColorTaskManagerSearchBarPlaceholderText)
 #endif
