--- remoting/host/me2me_desktop_environment.cc.orig	2023-01-17 19:19:00 UTC
+++ remoting/host/me2me_desktop_environment.cc
@@ -124,7 +124,7 @@ std::string Me2MeDesktopEnvironment::GetCapabilities()
     capabilities += protocol::kRemoteWebAuthnCapability;
   }
 
-#if BUILDFLAG(IS_LINUX) && defined(REMOTING_USE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(REMOTING_USE_X11)
   capabilities += " ";
   capabilities += protocol::kMultiStreamCapability;
 
@@ -180,7 +180,7 @@ bool Me2MeDesktopEnvironment::InitializeSecurity(
 
   // Otherwise, if the session is shared with the local user start monitoring
   // the local input and create the in-session UI.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   bool want_user_interface = false;
 #elif BUILDFLAG(IS_APPLE)
   // Don't try to display any UI on top of the system's login screen as this
