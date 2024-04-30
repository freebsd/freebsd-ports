--- src/3rdparty/chromium/chrome/browser/custom_handlers/chrome_protocol_handler_registry_delegate.cc.orig	2023-12-12 22:08:45 UTC
+++ src/3rdparty/chromium/chrome/browser/custom_handlers/chrome_protocol_handler_registry_delegate.cc
@@ -77,7 +77,7 @@ bool ChromeProtocolHandlerRegistryDelegate::ShouldRemo
 // If true default protocol handlers will be removed if the OS level
 // registration for a protocol is no longer Chrome.
 bool ChromeProtocolHandlerRegistryDelegate::ShouldRemoveHandlersNotInOS() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // We don't do this on Linux as the OS registration there is not reliable,
   // and Chrome OS doesn't have any notion of OS registration.
   // TODO(benwells): When Linux support is more reliable remove this
