--- src/3rdparty/chromium/net/base/network_change_notifier.h.orig	2017-01-26 00:49:16 UTC
+++ src/3rdparty/chromium/net/base/network_change_notifier.h
@@ -26,7 +26,7 @@ struct NetworkInterface;
 typedef std::vector<NetworkInterface> NetworkInterfaceList;
 class URLRequest;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 namespace internal {
 class AddressTrackerLinux;
 }
@@ -332,7 +332,7 @@ class NET_EXPORT NetworkChangeNotifier {
   // a large HOSTS file.
   static void GetDnsConfig(DnsConfig* config);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Returns the AddressTrackerLinux if present.
   static const internal::AddressTrackerLinux* GetAddressTracker();
 #endif
@@ -488,7 +488,7 @@ class NET_EXPORT NetworkChangeNotifier {
       const NetworkChangeCalculatorParams& params =
           NetworkChangeCalculatorParams());
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Returns the AddressTrackerLinux if present.
   // TODO(szym): Retrieve AddressMap from NetworkState. http://crbug.com/144212
   virtual const internal::AddressTrackerLinux*
