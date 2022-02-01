--- chrome/browser/media/webrtc/webrtc_logging_controller.h.orig	2021-12-14 11:44:58 UTC
+++ chrome/browser/media/webrtc/webrtc_logging_controller.h
@@ -132,13 +132,13 @@ class WebRtcLoggingController
                          size_t web_app_id,
                          const StartEventLoggingCallback& callback);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Ensures that the WebRTC Logs directory exists and then grants render
   // process access to the 'WebRTC Logs' directory, and invokes |callback| with
   // the ids necessary to create a DirectoryEntry object.
   void GetLogsDirectory(LogsDirectoryCallback callback,
                         LogsDirectoryErrorCallback error_callback);
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
   // chrome::mojom::WebRtcLoggingClient methods:
   void OnAddMessages(
@@ -191,7 +191,7 @@ class WebRtcLoggingController
       bool success,
       const std::string& error_message);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Grants the render process access to the 'WebRTC Logs' directory, and
   // invokes |callback| with the ids necessary to create a DirectoryEntry
   // object. If the |logs_path| couldn't be created or found, |error_callback|
@@ -199,7 +199,7 @@ class WebRtcLoggingController
   void GrantLogsDirectoryAccess(LogsDirectoryCallback callback,
                                 LogsDirectoryErrorCallback error_callback,
                                 const base::FilePath& logs_path);
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
   static base::FilePath GetLogDirectoryAndEnsureExists(
       const base::FilePath& browser_context_directory_path);
