--- net/base/mock_network_change_notifier.cc.orig	2023-08-18 10:26:52 UTC
+++ net/base/mock_network_change_notifier.cc
@@ -103,7 +103,7 @@ MockNetworkChangeNotifier::GetCurrentConnectionCost() 
   return connection_cost_;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 AddressMapOwnerLinux* MockNetworkChangeNotifier::GetAddressMapOwnerInternal() {
   return address_map_owner_;
 }
