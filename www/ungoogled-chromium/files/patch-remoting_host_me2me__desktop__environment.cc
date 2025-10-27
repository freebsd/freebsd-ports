--- remoting/host/me2me_desktop_environment.cc.orig	2025-10-21 16:57:35 UTC
+++ remoting/host/me2me_desktop_environment.cc
@@ -119,7 +119,7 @@ std::string Me2MeDesktopEnvironment::GetCapabilities()
     capabilities += protocol::kRemoteWebAuthnCapability;
   }
 
-#if BUILDFLAG(IS_LINUX) && defined(REMOTING_USE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(REMOTING_USE_X11)
   capabilities += " ";
   capabilities += protocol::kMultiStreamCapability;
   capabilities += " ";
@@ -168,7 +168,7 @@ Me2MeDesktopEnvironment::Me2MeDesktopEnvironment(
   // properly under Xvfb.
   mutable_desktop_capture_options()->set_use_update_notifications(true);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Setting this option to false means that the capture differ wrapper will not
   // be used when the X11 capturer is selected. This reduces the X11 capture
   // time by a few milliseconds per frame and is safe because we can rely on
@@ -195,7 +195,7 @@ bool Me2MeDesktopEnvironment::InitializeSecurity(
 
   // Otherwise, if the session is shared with the local user start monitoring
   // the local input and create the in-session UI.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   bool want_user_interface = false;
 #elif BUILDFLAG(IS_APPLE)
   // Don't try to display any UI on top of the system's login screen as this
