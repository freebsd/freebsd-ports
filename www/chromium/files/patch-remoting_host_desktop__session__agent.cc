--- remoting/host/desktop_session_agent.cc.orig	2026-11-11 14:44:17 UTC
+++ remoting/host/desktop_session_agent.cc
@@ -661,7 +661,7 @@ void DesktopSessionAgent::OnDesktopEnvironmentCreated(
   // LocalInputMonitorWin filters out an echo of the injected input before it
   // reaches |remote_input_filter_|.
   remote_input_filter_->SetExpectLocalEcho(false);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // LocalMouseInputMonitorX11 filters out XTest-injected input before it
   // reaches `remote_input_filter_`.
   if (!webrtc::DesktopCapturer::IsRunningUnderWayland()) {
