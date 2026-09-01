--- remoting/host/desktop_session_connector.h.orig	2026-08-31 10:59:09 UTC
+++ remoting/host/desktop_session_connector.h
@@ -59,7 +59,7 @@ class DesktopSessionConnector : public mojom::DesktopS
   // connections.
   virtual void SetRequiredUsername(std::string_view username) = 0;
 
-#if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   // Notifies the network process that |terminal_id| is now attached to
   // a desktop integration process. |desktop_pipe| is the client end of the pipe
   // opened by the desktop process.
