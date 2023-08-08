--- src/3rdparty/chromium/content/browser/renderer_host/delegated_frame_host.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/content/browser/renderer_host/delegated_frame_host.cc
@@ -258,7 +258,7 @@ void DelegatedFrameHost::EmbedSurface(
 
   if (!primary_surface_id ||
       primary_surface_id->local_surface_id() != local_surface_id_) {
-#if defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
     // On Windows and Linux, we would like to produce new content as soon as
     // possible or the OS will create an additional black gutter. Until we can
     // block resize on surface synchronization on these platforms, we will not
