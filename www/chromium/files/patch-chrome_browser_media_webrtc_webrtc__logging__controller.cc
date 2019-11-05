--- chrome/browser/media/webrtc/webrtc_logging_controller.cc.orig	2019-10-30 15:49:45 UTC
+++ chrome/browser/media/webrtc/webrtc_logging_controller.cc
@@ -24,10 +24,10 @@
 #include "content/public/browser/render_process_host.h"
 #include "services/service_manager/public/cpp/connector.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "content/public/browser/child_process_security_policy.h"
 #include "storage/browser/fileapi/isolated_context.h"
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 using webrtc_event_logging::WebRtcEventLogManager;
 
@@ -267,7 +267,7 @@ void WebRtcLoggingController::StartEventLogging(
       web_app_id, callback);
 }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 void WebRtcLoggingController::GetLogsDirectory(
     const LogsDirectoryCallback& callback,
     const LogsDirectoryErrorCallback& error_callback) {
@@ -312,7 +312,7 @@ void WebRtcLoggingController::GrantLogsDirectoryAccess
   base::SequencedTaskRunnerHandle::Get()->PostTask(
       FROM_HERE, base::BindOnce(callback, file_system.id(), registered_name));
 }
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 void WebRtcLoggingController::OnRtpPacket(
     std::unique_ptr<uint8_t[]> packet_header,
