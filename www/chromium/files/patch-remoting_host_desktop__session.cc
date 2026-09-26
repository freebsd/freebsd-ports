--- remoting/host/desktop_session.cc.orig	2026-09-25 15:26:43 UTC
+++ remoting/host/desktop_session.cc
@@ -23,7 +23,7 @@ void DesktopSession::SetReceiver(
   if (receiver.is_valid()) {
     receiver_.reset();
     receiver_.Bind(std::move(receiver));
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // On platforms without persistent desktop sessions, immediately close the
     // desktop session when the control pipe drops so that background agents
     // (e.g. `remoting_desktop.exe`) are torn down and resources released.
