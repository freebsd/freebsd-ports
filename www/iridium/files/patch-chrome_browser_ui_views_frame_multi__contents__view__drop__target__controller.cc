--- chrome/browser/ui/views/frame/multi_contents_view_drop_target_controller.cc.orig	2026-02-16 10:45:29 UTC
+++ chrome/browser/ui/views/frame/multi_contents_view_drop_target_controller.cc
@@ -35,7 +35,7 @@ static constexpr base::TimeDelta kShowNudgeDelay = bas
 static constexpr int kDropTargetHideForOSWidth =
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN)
     32;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     50;
 #else
     0;
