--- remoting/host/peer_session_impl.cc.orig	2026-08-31 10:59:09 UTC
+++ remoting/host/peer_session_impl.cc
@@ -307,7 +307,7 @@ void PeerSessionImpl::NotifyClientResolution(
   if (effective_policies_.curtain_required.value_or(false)) {
     dpi_vector.set(resolution.x_dpi(), resolution.y_dpi());
   }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   dpi_vector.set(resolution.x_dpi(), resolution.y_dpi());
 #endif
 
