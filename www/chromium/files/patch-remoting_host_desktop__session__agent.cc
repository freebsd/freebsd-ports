--- remoting/host/desktop_session_agent.cc.orig	2026-10-18 13:29:39 UTC
+++ remoting/host/desktop_session_agent.cc
@@ -679,7 +679,7 @@ void DesktopSessionAgent::OnDesktopEnvironmentCreated(
   // LocalInputMonitorWin filters out an echo of the injected input before it
   // reaches |remote_input_filter_|.
   remote_input_filter_->SetExpectLocalEcho(false);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // LocalMouseInputMonitorX11 filters out XTest-injected input before it
   // reaches `remote_input_filter_`.
   if (!webrtc::DesktopCapturer::IsRunningUnderWayland()) {
