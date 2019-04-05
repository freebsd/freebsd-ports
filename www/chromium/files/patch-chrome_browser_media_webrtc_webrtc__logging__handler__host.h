--- chrome/browser/media/webrtc/webrtc_logging_handler_host.h.orig	2019-03-17 20:00:30 UTC
+++ chrome/browser/media/webrtc/webrtc_logging_handler_host.h
@@ -154,13 +154,13 @@ class WebRtcLoggingHandlerHost : public content::Brows
                          size_t web_app_id,
                          const StartEventLoggingCallback& callback);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Ensures that the WebRTC Logs directory exists and then grants render
   // process access to the 'WebRTC Logs' directory, and invokes |callback| with
   // the ids necessary to create a DirectoryEntry object.
   void GetLogsDirectory(const LogsDirectoryCallback& callback,
                         const LogsDirectoryErrorCallback& error_callback);
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
  private:
   friend class content::BrowserThread;
@@ -227,7 +227,7 @@ class WebRtcLoggingHandlerHost : public content::Brows
       bool success,
       const std::string& error_message);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Grants the render process access to the 'WebRTC Logs' directory, and
   // invokes |callback| with the ids necessary to create a DirectoryEntry
   // object. If the |logs_path| couldn't be created or found, |error_callback|
@@ -236,7 +236,7 @@ class WebRtcLoggingHandlerHost : public content::Brows
       const LogsDirectoryCallback& callback,
       const LogsDirectoryErrorCallback& error_callback,
       const base::FilePath& logs_path);
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
   // The render process ID this object belongs to.
   const int render_process_id_;
