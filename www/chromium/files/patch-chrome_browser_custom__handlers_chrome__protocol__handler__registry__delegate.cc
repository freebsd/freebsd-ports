--- chrome/browser/custom_handlers/chrome_protocol_handler_registry_delegate.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/custom_handlers/chrome_protocol_handler_registry_delegate.cc
@@ -69,7 +69,7 @@ void ChromeProtocolHandlerRegistryDelegate::CheckDefau
 // If true default protocol handlers will be removed if the OS level
 // registration for a protocol is no longer Chrome.
 bool ChromeProtocolHandlerRegistryDelegate::ShouldRemoveHandlersNotInOS() {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // We don't do this on Linux as the OS registration there is not reliable,
   // and Chrome OS doesn't have any notion of OS registration.
   // TODO(benwells): When Linux support is more reliable remove this
