--- src/remoting/host/peer_session_impl.cc.orig	2026-10-18 18:43:23 UTC
+++ src/remoting/host/peer_session_impl.cc
@@ -251,7 +251,7 @@ void PeerSessionImpl::NotifyClientResolu
   if (effective_policies_.curtain_required.value_or(false)) {
     dpi_vector.set(resolution.x_dpi(), resolution.y_dpi());
   }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   dpi_vector.set(resolution.x_dpi(), resolution.y_dpi());
 #endif
 
