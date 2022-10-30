--- remoting/host/me2me_desktop_environment.cc.orig	2022-10-29 17:50:56 UTC
+++ remoting/host/me2me_desktop_environment.cc
@@ -41,7 +41,7 @@ namespace remoting {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 constexpr char kUseXvfbEnvVar[] = "CHROME_REMOTE_DESKTOP_USE_XVFB";
 
@@ -114,7 +114,7 @@ std::string Me2MeDesktopEnvironment::GetCapabilities()
     capabilities += protocol::kRemoteWebAuthnCapability;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Multi-stream and client-controlled layout are only supported with
   // Xorg+Dummy.
   // TODO(crbug.com/1366595): Either just remove this check if the dependency
@@ -175,7 +175,7 @@ bool Me2MeDesktopEnvironment::InitializeSecurity(
 
   // Otherwise, if the session is shared with the local user start monitoring
   // the local input and create the in-session UI.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   bool want_user_interface = false;
 #elif BUILDFLAG(IS_APPLE)
   // Don't try to display any UI on top of the system's login screen as this
