--- extensions/browser/api/networking_private/networking_private_event_router_factory.cc.orig	2016-12-16 19:26:17.392697000 +0000
+++ extensions/browser/api/networking_private/networking_private_event_router_factory.cc	2016-12-16 19:29:29.232668000 +0000
@@ -13,6 +13,7 @@
 
 namespace extensions {
 
+#if !defined(OS_BSD)
 // static
 NetworkingPrivateEventRouter*
 NetworkingPrivateEventRouterFactory::GetForProfile(
@@ -57,5 +58,6 @@
 bool NetworkingPrivateEventRouterFactory::ServiceIsNULLWhileTesting() const {
   return true;
 }
+#endif
 
 }  // namespace extensions
