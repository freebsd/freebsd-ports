--- chrome/browser/media/webrtc/webrtc_logging_controller.cc.orig	2020-03-16 18:39:44 UTC
+++ chrome/browser/media/webrtc/webrtc_logging_controller.cc
@@ -24,10 +24,10 @@
 #include "content/public/browser/render_process_host.h"
 #include "services/service_manager/public/cpp/connector.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "content/public/browser/child_process_security_policy.h"
 #include "storage/browser/file_system/isolated_context.h"
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 using webrtc_event_logging::WebRtcEventLogManager;
 
@@ -270,7 +270,7 @@ void WebRtcLoggingController::StartEventLogging(
       web_app_id, callback);
 }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 void WebRtcLoggingController::GetLogsDirectory(
     const LogsDirectoryCallback& callback,
     const LogsDirectoryErrorCallback& error_callback) {
@@ -315,7 +315,7 @@ void WebRtcLoggingController::GrantLogsDirectoryAccess
   base::SequencedTaskRunnerHandle::Get()->PostTask(
       FROM_HERE, base::BindOnce(callback, file_system.id(), registered_name));
 }
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 void WebRtcLoggingController::OnRtpPacket(
     std::unique_ptr<uint8_t[]> packet_header,
