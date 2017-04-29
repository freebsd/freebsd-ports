--- extensions/browser/api/networking_private/networking_private_event_router_factory.cc.orig	2017-04-19 19:06:34 UTC
+++ extensions/browser/api/networking_private/networking_private_event_router_factory.cc
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
