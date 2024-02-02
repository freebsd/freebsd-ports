--- remoting/host/base/desktop_environment_options.cc.orig	2024-01-30 07:53:34 UTC
+++ remoting/host/base/desktop_environment_options.cc
@@ -118,7 +118,7 @@ bool DesktopEnvironmentOptions::capture_video_on_dedic
   // TODO(joedow): Determine whether we can migrate additional platforms to
   // using the DesktopCaptureWrapper instead of the DesktopCaptureProxy. Then
   // clean up DesktopCapturerProxy::Core::CreateCapturer().
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return capture_video_on_dedicated_thread_;
 #else
   return false;
