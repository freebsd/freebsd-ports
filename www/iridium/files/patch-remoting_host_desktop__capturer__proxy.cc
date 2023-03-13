--- remoting/host/desktop_capturer_proxy.cc.orig	2023-03-13 07:33:08 UTC
+++ remoting/host/desktop_capturer_proxy.cc
@@ -30,7 +30,7 @@
 #include "remoting/host/chromeos/frame_sink_desktop_capturer.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/environment.h"
 #include "base/nix/xdg_util.h"
 #include "remoting/host/linux/wayland_desktop_capturer.h"
@@ -96,7 +96,7 @@ void DesktopCapturerProxy::Core::CreateCapturer(
     capturer_ = std::make_unique<webrtc::DesktopCapturerDifferWrapper>(
         std::make_unique<AuraDesktopCapturer>());
   }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   static base::nix::SessionType session_type = base::nix::SessionType::kUnset;
   if (session_type == base::nix::SessionType::kUnset) {
     std::unique_ptr<base::Environment> env = base::Environment::Create();
