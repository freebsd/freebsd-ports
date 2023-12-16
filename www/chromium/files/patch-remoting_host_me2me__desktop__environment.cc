--- remoting/host/me2me_desktop_environment.cc.orig	2023-12-10 06:10:27 UTC
+++ remoting/host/me2me_desktop_environment.cc
@@ -125,7 +125,7 @@ std::string Me2MeDesktopEnvironment::GetCapabilities()
     capabilities += protocol::kRemoteWebAuthnCapability;
   }
 
-#if BUILDFLAG(IS_LINUX) && defined(REMOTING_USE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(REMOTING_USE_X11)
   if (!IsRunningWayland()) {
     capabilities += " ";
     capabilities += protocol::kMultiStreamCapability;
@@ -171,7 +171,7 @@ Me2MeDesktopEnvironment::Me2MeDesktopEnvironment(
   // properly under Xvfb.
   mutable_desktop_capture_options()->set_use_update_notifications(true);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Setting this option to false means that the capture differ wrapper will not
   // be used when the X11 capturer is selected. This reduces the X11 capture
   // time by a few milliseconds per frame and is safe because we can rely on
@@ -180,7 +180,7 @@ Me2MeDesktopEnvironment::Me2MeDesktopEnvironment(
   mutable_desktop_capture_options()->set_detect_updated_region(false);
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (IsRunningWayland()) {
     mutable_desktop_capture_options()->set_prefer_cursor_embedded(false);
   }
@@ -205,7 +205,7 @@ bool Me2MeDesktopEnvironment::InitializeSecurity(
 
   // Otherwise, if the session is shared with the local user start monitoring
   // the local input and create the in-session UI.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   bool want_user_interface = false;
 #elif BUILDFLAG(IS_APPLE)
   // Don't try to display any UI on top of the system's login screen as this
