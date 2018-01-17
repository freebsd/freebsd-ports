--- src/3rdparty/chromium/net/base/network_interfaces_linux.cc.orig	2017-01-26 00:49:16 UTC
+++ src/3rdparty/chromium/net/base/network_interfaces_linux.cc
@@ -6,12 +6,14 @@
 
 #include <memory>
 
+#if !defined(OS_FREEBSD)
 #if !defined(OS_ANDROID)
 #include <linux/ethtool.h>
 #endif  // !defined(OS_ANDROID)
 #include <linux/if.h>
 #include <linux/sockios.h>
 #include <linux/wireless.h>
+#endif  // !defined(OS_FREEBSD)
 #include <set>
 #include <sys/ioctl.h>
 #include <sys/types.h>
@@ -49,6 +51,7 @@ bool TryConvertNativeToNetIPAttributes(i
   // are still progressing through duplicated address detection (DAD)
   // and shouldn't be used by the application layer until DAD process
   // is completed.
+#if !defined(OS_FREEBSD)
   if (native_attributes & (
 #if !defined(OS_ANDROID)
                               IFA_F_OPTIMISTIC | IFA_F_DADFAILED |
@@ -66,6 +69,10 @@ bool TryConvertNativeToNetIPAttributes(i
   }
 
   return true;
+#else
+  // the flags tested above are not present on FreeBSD
+  return false;
+#endif  // !OS_FREEBSD
 }
 
 }  // namespace
@@ -80,13 +87,15 @@ NetworkChangeNotifier::ConnectionType Ge
   if (!s.is_valid())
     return NetworkChangeNotifier::CONNECTION_UNKNOWN;
 
+#if !defined(OS_FREEBSD)
   // Test wireless extensions for CONNECTION_WIFI
   struct iwreq pwrq = {};
   strncpy(pwrq.ifr_name, ifname.c_str(), IFNAMSIZ - 1);
   if (ioctl(s.get(), SIOCGIWNAME, &pwrq) != -1)
     return NetworkChangeNotifier::CONNECTION_WIFI;
+#endif  // !defined(OS_FREEBSD)
 
-#if !defined(OS_ANDROID)
+#if !defined(OS_ANDROID) && !defined(OS_FREEBSD)
   // Test ethtool for CONNECTION_ETHERNET
   struct ethtool_cmd ecmd = {};
   ecmd.cmd = ETHTOOL_GSET;
@@ -95,12 +104,13 @@ NetworkChangeNotifier::ConnectionType Ge
   strncpy(ifr.ifr_name, ifname.c_str(), IFNAMSIZ - 1);
   if (ioctl(s.get(), SIOCETHTOOL, &ifr) != -1)
     return NetworkChangeNotifier::CONNECTION_ETHERNET;
-#endif  // !defined(OS_ANDROID)
+#endif  // !defined(OS_ANDROID) && !defined(OS_FREEBSD)
 
   return NetworkChangeNotifier::CONNECTION_UNKNOWN;
 }
 
 std::string GetInterfaceSSID(const std::string& ifname) {
+#if !defined(OS_FREEBSD)
   base::ScopedFD ioctl_socket(socket(AF_INET, SOCK_DGRAM, 0));
   if (!ioctl_socket.is_valid())
     return "";
@@ -112,9 +122,11 @@ std::string GetInterfaceSSID(const std::
   wreq.u.essid.length = IW_ESSID_MAX_SIZE;
   if (ioctl(ioctl_socket.get(), SIOCGIWESSID, &wreq) != -1)
     return ssid;
+#endif  // !defined(OS_FREEBSD)
   return "";
 }
 
+#if !defined(OS_FREEBSD)
 bool GetNetworkListImpl(
     NetworkInterfaceList* networks,
     int policy,
@@ -183,6 +195,7 @@ bool GetNetworkListImpl(
 
   return true;
 }
+#endif  // !defined(OS_FREEBSD)
 
 std::string GetWifiSSIDFromInterfaceListInternal(
     const NetworkInterfaceList& interfaces,
@@ -207,12 +220,16 @@ bool GetNetworkList(NetworkInterfaceList
   if (networks == NULL)
     return false;
 
+#if !defined(OS_FREEBSD)
   internal::AddressTrackerLinux tracker;
   tracker.Init();
 
   return internal::GetNetworkListImpl(
       networks, policy, tracker.GetOnlineLinks(), tracker.GetAddressMap(),
       &internal::AddressTrackerLinux::GetInterfaceName);
+#else
+  return false;
+#endif
 }
 
 std::string GetWifiSSID() {
