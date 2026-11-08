--- remoting/host/it2me/it2me_host.cc.orig	2026-10-18 13:29:39 UTC
+++ remoting/host/it2me/it2me_host.cc
@@ -74,7 +74,7 @@
 #include "remoting/host/chromeos/features.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "remoting/host/linux/gnome_remote_desktop_session.h"
 #include "remoting/host/linux/portal_remote_desktop_session.h"
 #endif
@@ -286,7 +286,7 @@ void It2MeHost::ConnectOnNetworkThread(
 
   SetState(It2MeHostState::kStarting, ErrorCode::OK);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!GnomeRemoteDesktopSession::IsRunningUnderGnome()) {
     PortalRemoteDesktopSession::GetInstance()->SetCreateVirtualMonitor(false);
   }
