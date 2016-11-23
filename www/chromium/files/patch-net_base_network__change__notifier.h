--- net/base/network_change_notifier.h.orig	2016-08-03 22:02:21.000000000 +0300
+++ net/base/network_change_notifier.h	2016-09-26 03:54:03.417293000 +0300
@@ -26,7 +26,7 @@
 typedef std::vector<NetworkInterface> NetworkInterfaceList;
 class URLRequest;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 namespace internal {
 class AddressTrackerLinux;
 }
@@ -329,7 +329,7 @@
   // a large HOSTS file.
   static void GetDnsConfig(DnsConfig* config);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Returns the AddressTrackerLinux if present.
   static const internal::AddressTrackerLinux* GetAddressTracker();
 #endif
@@ -485,7 +485,7 @@
       const NetworkChangeCalculatorParams& params =
           NetworkChangeCalculatorParams());
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Returns the AddressTrackerLinux if present.
   // TODO(szym): Retrieve AddressMap from NetworkState. http://crbug.com/144212
   virtual const internal::AddressTrackerLinux*
