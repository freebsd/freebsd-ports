--- net/base/network_change_notifier.h.orig	2021-12-14 11:45:08 UTC
+++ net/base/network_change_notifier.h
@@ -416,7 +416,7 @@ class NET_EXPORT NetworkChangeNotifier {
   // Chrome net code.
   static SystemDnsConfigChangeNotifier* GetSystemDnsConfigNotifier();
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Returns the AddressTrackerLinux if present.
   static const internal::AddressTrackerLinux* GetAddressTracker();
 #endif
@@ -573,7 +573,7 @@ class NET_EXPORT NetworkChangeNotifier {
       SystemDnsConfigChangeNotifier* system_dns_config_notifier = nullptr,
       bool omit_observers_in_constructor_for_testing = false);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Returns the AddressTrackerLinux if present.
   // TODO(szym): Retrieve AddressMap from NetworkState. http://crbug.com/144212
   virtual const internal::AddressTrackerLinux*
