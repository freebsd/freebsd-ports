--- chrome/browser/sharing/sharing_service.cc.orig	2020-03-30 09:34:43 UTC
+++ chrome/browser/sharing/sharing_service.cc
@@ -30,7 +30,7 @@ namespace {
 SharingMessageSender::DelegateType GetSendDelegateType(
     const syncer::DeviceInfo& device,
     const chrome_browser_sharing::SharingMessage& message) {
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
   // Messages other than SharedClipboard are always sent via FCM.
   if (message.payload_case() !=
@@ -56,7 +56,7 @@ SharingMessageSender::DelegateType GetSendDelegateType
   // logic once we wrap up the experiment and e.g. only send messages over a
   // certain size via WebRTC.
   return SharingMessageSender::DelegateType::kWebRtc;
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
         // defined(OS_CHROMEOS)
 
   // Only FCM is supported for non desktop OS.
