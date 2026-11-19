--- remoting/host/peer_session_impl.cc.orig	2026-11-19 12:25:27 UTC
+++ remoting/host/peer_session_impl.cc
@@ -196,7 +196,7 @@ PeerSessionImpl::PeerSessionImpl(
   // LocalMouseInputMonitorMac filter out an echo of the injected input before
   // it reaches `remote_input_filter_`.
   input_pipeline_.remote_input_filter()->SetExpectLocalEcho(false);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // LocalMouseInputMonitorX11 filters out XTest-injected input before it
   // reaches `remote_input_filter_`. On Wayland, PipewireLocalInputMonitor
   // observes global cursor positions from PipeWire and still relies on echo
@@ -301,7 +301,7 @@ void PeerSessionImpl::NotifyClientResolution(
   if (effective_policies_.curtain_required.value_or(false)) {
     dpi_vector.set(resolution.x_dpi(), resolution.y_dpi());
   }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   dpi_vector.set(resolution.x_dpi(), resolution.y_dpi());
 #endif
 
