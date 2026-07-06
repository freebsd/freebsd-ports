--- remoting/host/it2me/it2me_host.cc.orig	2026-06-05 13:45:06 UTC
+++ remoting/host/it2me/it2me_host.cc
@@ -72,7 +72,7 @@
 #include "remoting/host/chromeos/features.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "remoting/host/linux/gnome_remote_desktop_session.h"
 #include "remoting/host/linux/portal_remote_desktop_session.h"
 #endif
@@ -283,7 +283,7 @@ void It2MeHost::ConnectOnNetworkThread(
 
   SetState(It2MeHostState::kStarting, ErrorCode::OK);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!GnomeRemoteDesktopSession::IsRunningUnderGnome()) {
     PortalRemoteDesktopSession::GetInstance()->SetCreateVirtualMonitor(false);
   }
