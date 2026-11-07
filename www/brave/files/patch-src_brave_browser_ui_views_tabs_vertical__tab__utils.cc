--- src/brave/browser/ui/views/tabs/vertical_tab_utils.cc.orig	2026-06-01 00:00:00 UTC
+++ src/brave/browser/ui/views/tabs/vertical_tab_utils.cc
@@ -101,7 +101,8 @@
   // On Mac, frame_view->GetBrowserLayoutParams() gives more wider width than
   // we want.
   return {80, 0};
-#elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+// The #else branch is a hard #error, so FreeBSD has to take the Linux path.
+#elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto* frame_view = frame->GetFrameView();
   if (!frame_view) {
     return {};
