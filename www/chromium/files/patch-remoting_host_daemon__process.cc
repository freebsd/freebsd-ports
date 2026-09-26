--- remoting/host/daemon_process.cc.orig	2026-09-25 15:26:43 UTC
+++ remoting/host/daemon_process.cc
@@ -274,7 +274,7 @@ void DaemonProcess::GetDesktopSession(
   // Windows, user sessions and applications are persisted natively by the OS,
   // and the desktop process is purely a transient capture/input agent that is
   // recreated per connection.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const std::string& client_id = options->client_id;
   auto it = std::ranges::find_if(desktop_sessions_, [&](const auto& pair) {
     return !client_id.empty() && pair.second->client_id() == client_id;
