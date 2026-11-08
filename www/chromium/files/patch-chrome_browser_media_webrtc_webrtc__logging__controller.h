--- chrome/browser/media/webrtc/webrtc_logging_controller.h.orig	2026-10-18 13:29:39 UTC
+++ chrome/browser/media/webrtc/webrtc_logging_controller.h
@@ -160,7 +160,7 @@ class WebRtcLoggingController
 
   base::RepeatingCallback<void(const std::string&)> GetLogMessageCallback();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   // Ensures that the WebRTC Logs directory exists and then grants render
   // process access to the 'WebRTC Logs' directory, and invokes |callback| with
   // the ids necessary to create a DirectoryEntry object.
@@ -244,7 +244,7 @@ class WebRtcLoggingController
   bool CheckCanOperationProceed(GenericDoneCallback& callback);
   bool CheckCanOperationProceed(UploadDoneCallback& callback);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   // Grants the render process access to the 'WebRTC Logs' directory, and
   // invokes |callback| with the ids necessary to create a DirectoryEntry
   // object. If the |logs_path| couldn't be created or found, |error_callback|
