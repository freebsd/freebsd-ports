--- chrome/browser/ui/views/task_manager_search_bar_view.cc.orig	2026-02-11 09:05:39 UTC
+++ chrome/browser/ui/views/task_manager_search_bar_view.cc
@@ -29,7 +29,7 @@ TaskManagerSearchBarView::TaskManagerSearchBarView(
     const gfx::Insets& margins,
     Delegate& delegate)
     : delegate_(delegate)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       ,
       textfield_placeholder_color_id_(kColorTaskManagerSearchBarPlaceholderText)
 #endif
