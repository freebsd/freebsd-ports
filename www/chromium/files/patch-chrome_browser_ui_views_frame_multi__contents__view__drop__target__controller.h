--- chrome/browser/ui/views/frame/multi_contents_view_drop_target_controller.h.orig	2026-03-13 06:02:14 UTC
+++ chrome/browser/ui/views/frame/multi_contents_view_drop_target_controller.h
@@ -32,7 +32,7 @@ class MultiContentsViewDropTargetController final
       public MultiContentsDropTargetView::DragDelegate {
  public:
   static constexpr base::TimeDelta kShowDropTargetForTabDelay =
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       base::Milliseconds(1000);
 #else
       base::Milliseconds(500);
