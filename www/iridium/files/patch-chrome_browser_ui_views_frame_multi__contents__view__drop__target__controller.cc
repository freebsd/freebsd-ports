--- chrome/browser/ui/views/frame/multi_contents_view_drop_target_controller.cc.orig	2026-08-13 16:48:13 UTC
+++ chrome/browser/ui/views/frame/multi_contents_view_drop_target_controller.cc
@@ -59,7 +59,7 @@ int MultiContentsViewDropTargetController::DropTargetC
   return
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN)
       32;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       50;
 #else
       0;
