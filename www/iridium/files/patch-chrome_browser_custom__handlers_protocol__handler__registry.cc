--- chrome/browser/custom_handlers/protocol_handler_registry.cc.orig	2020-02-03 21:52:39 UTC
+++ chrome/browser/custom_handlers/protocol_handler_registry.cc
@@ -42,7 +42,7 @@ const ProtocolHandler& LookupHandler(
 // If true default protocol handlers will be removed if the OS level
 // registration for a protocol is no longer Chrome.
 bool ShouldRemoveHandlersNotInOS() {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // We don't do this on Linux as the OS registration there is not reliable,
   // and Chrome OS doesn't have any notion of OS registration.
   // TODO(benwells): When Linux support is more reliable remove this
