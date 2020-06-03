--- chrome/browser/sharing/sharing_service.cc.orig	2020-05-13 18:40:22 UTC
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
@@ -59,7 +59,7 @@ SharingMessageSender::DelegateType GetSendDelegateType
 #else
   // Only FCM is supported for non desktop OS.
   return SharingMessageSender::DelegateType::kFCM;
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 }
 
