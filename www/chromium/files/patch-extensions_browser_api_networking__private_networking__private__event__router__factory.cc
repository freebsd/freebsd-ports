--- extensions/browser/api/networking_private/networking_private_event_router_factory.cc.orig	2017-06-05 19:03:07 UTC
+++ extensions/browser/api/networking_private/networking_private_event_router_factory.cc
@@ -13,6 +13,7 @@
 
 namespace extensions {
 
+#if !defined(OS_BSD)
 // static
 NetworkingPrivateEventRouter*
 NetworkingPrivateEventRouterFactory::GetForProfile(
@@ -57,5 +58,6 @@ bool NetworkingPrivateEventRouterFactory::ServiceIsCre
 bool NetworkingPrivateEventRouterFactory::ServiceIsNULLWhileTesting() const {
   return true;
 }
+#endif
 
 }  // namespace extensions
