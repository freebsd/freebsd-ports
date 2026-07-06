--- chrome/browser/ui/views/frame/multi_contents_view_drop_target_controller.cc.orig	2026-07-01 06:24:19 UTC
+++ chrome/browser/ui/views/frame/multi_contents_view_drop_target_controller.cc
@@ -36,7 +36,7 @@ static constexpr base::TimeDelta kShowNudgeDelay = bas
 static constexpr int kDropTargetHideForOSWidth =
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN)
     32;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     50;
 #else
     0;
