--- src/3rdparty/chromium/net/base/network_change_notifier.h.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/net/base/network_change_notifier.h
@@ -22,7 +22,7 @@ class NetworkChangeNotifierFactory;
 struct NetworkInterface;
 typedef std::vector<NetworkInterface> NetworkInterfaceList;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 namespace internal {
 class AddressTrackerLinux;
 }
@@ -348,7 +348,7 @@ class NET_EXPORT NetworkChangeNotifier {
   // a large HOSTS file.
   static void GetDnsConfig(DnsConfig* config);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Returns the AddressTrackerLinux if present.
   static const internal::AddressTrackerLinux* GetAddressTracker();
 #endif
@@ -499,7 +499,7 @@ class NET_EXPORT NetworkChangeNotifier {
       const NetworkChangeCalculatorParams& params =
           NetworkChangeCalculatorParams());
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Returns the AddressTrackerLinux if present.
   // TODO(szym): Retrieve AddressMap from NetworkState. http://crbug.com/144212
   virtual const internal::AddressTrackerLinux*
