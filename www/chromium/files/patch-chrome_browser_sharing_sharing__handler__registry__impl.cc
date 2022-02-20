--- chrome/browser/sharing/sharing_handler_registry_impl.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/sharing/sharing_handler_registry_impl.cc
@@ -24,7 +24,7 @@
 #endif  // defined(OS_ANDROID)
 
 #if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "chrome/browser/sharing/shared_clipboard/remote_copy_message_handler.h"
 #endif  // defined(OS_WIN) || defined(OS_MAC) || (defined(OS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS_LACROS)) defined(OS_CHROMEOS)
@@ -77,7 +77,7 @@ SharingHandlerRegistryImpl::SharingHandlerRegistryImpl
   }
 
 #if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
   if (sharing_device_registration->IsRemoteCopySupported()) {
     AddSharingHandler(
         std::make_unique<RemoteCopyMessageHandler>(profile),
