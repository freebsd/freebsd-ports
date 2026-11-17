--- src/remoting/host/base/desktop_environment_options.cc.orig	2026-10-18 18:43:23 UTC
+++ src/remoting/host/base/desktop_environment_options.cc
@@ -117,7 +117,7 @@ bool DesktopEnvironmentOptions::capture_
   // TODO(joedow): Determine whether we can migrate additional platforms to
   // using the DesktopCaptureWrapper instead of the DesktopCaptureProxy. Then
   // clean up DesktopCapturerProxy::Core::CreateCapturer().
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return capture_video_on_dedicated_thread_;
 #else
   return false;
