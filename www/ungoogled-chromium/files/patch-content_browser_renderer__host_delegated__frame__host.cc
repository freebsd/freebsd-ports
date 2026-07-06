--- content/browser/renderer_host/delegated_frame_host.cc.orig	2026-06-05 13:45:06 UTC
+++ content/browser/renderer_host/delegated_frame_host.cc
@@ -353,7 +353,7 @@ void DelegatedFrameHost::EmbedSurface(
 
   if (!primary_surface_id ||
       primary_surface_id->local_surface_id() != local_surface_id_) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     // On Windows, Linux, and macOS, we would like to produce new content as
     // soon as possible or the OS will create an additional black gutter.
     // Until we can block resize on surface synchronization on these
