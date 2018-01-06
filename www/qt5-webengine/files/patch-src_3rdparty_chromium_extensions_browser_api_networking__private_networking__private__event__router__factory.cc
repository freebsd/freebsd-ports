--- src/3rdparty/chromium/extensions/browser/api/networking_private/networking_private_event_router_factory.cc.orig	2017-01-26 00:49:14 UTC
+++ src/3rdparty/chromium/extensions/browser/api/networking_private/networking_private_event_router_factory.cc
@@ -13,6 +13,7 @@
 
 namespace extensions {
 
+#if !defined(OS_BSD)
 // static
 NetworkingPrivateEventRouter*
 NetworkingPrivateEventRouterFactory::GetForProfile(
@@ -57,5 +58,6 @@ bool NetworkingPrivateEventRouterFactory
 bool NetworkingPrivateEventRouterFactory::ServiceIsNULLWhileTesting() const {
   return true;
 }
+#endif
 
 }  // namespace extensions
