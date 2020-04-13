--- chrome/browser/sharing/sharing_handler_registry_impl.cc.orig	2020-03-16 18:39:44 UTC
+++ chrome/browser/sharing/sharing_handler_registry_impl.cc
@@ -24,10 +24,10 @@
 #include "chrome/browser/sharing/webrtc/webrtc_message_handler.h"
 #endif  // defined(OS_ANDROID)
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 #include "chrome/browser/sharing/shared_clipboard/remote_copy_message_handler.h"
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
 SharingHandlerRegistryImpl::SharingHandlerRegistryImpl(
@@ -73,14 +73,14 @@ SharingHandlerRegistryImpl::SharingHandlerRegistryImpl
         {chrome_browser_sharing::SharingMessage::kSharedClipboardMessage});
   }
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
   if (sharing_device_registration->IsRemoteCopySupported()) {
     AddSharingHandler(
         std::make_unique<RemoteCopyMessageHandler>(profile),
         {chrome_browser_sharing::SharingMessage::kRemoteCopyMessage});
   }
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
 #if !defined(OS_ANDROID)
