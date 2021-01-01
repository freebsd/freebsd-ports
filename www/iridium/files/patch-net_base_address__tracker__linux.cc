--- net/base/address_tracker_linux.cc.orig	2020-03-03 18:53:55 UTC
+++ net/base/address_tracker_linux.cc
@@ -5,7 +5,9 @@
 #include "net/base/address_tracker_linux.h"
 
 #include <errno.h>
+#if !defined(OS_BSD)
 #include <linux/if.h>
+#endif
 #include <stdint.h>
 #include <sys/ioctl.h>
 #include <utility>
@@ -177,6 +179,7 @@ AddressTrackerLinux::AddressTrackerLinux(
 AddressTrackerLinux::~AddressTrackerLinux() = default;
 
 void AddressTrackerLinux::Init() {
+#if !defined(OS_FREEBSD)
   netlink_fd_.reset(socket(AF_NETLINK, SOCK_RAW, NETLINK_ROUTE));
   if (!netlink_fd_.is_valid()) {
     PLOG(ERROR) << "Could not create NETLINK socket";
@@ -272,6 +275,7 @@ void AddressTrackerLinux::AbortAndForceOnline() {
   connection_type_initialized_cv_.Broadcast();
 }
 
+#if !defined(OS_BSD)
 AddressTrackerLinux::AddressMap AddressTrackerLinux::GetAddressMap() const {
   AddressTrackerAutoLock lock(*this, address_map_lock_);
   return address_map_;
@@ -290,6 +294,7 @@ bool AddressTrackerLinux::IsInterfaceIgnored(int inter
   const char* interface_name = get_interface_name_(interface_index, buf);
   return ignored_interfaces_.find(interface_name) != ignored_interfaces_.end();
 }
+#endif // !OS_BSD
 
 NetworkChangeNotifier::ConnectionType
 AddressTrackerLinux::GetCurrentConnectionType() {
@@ -348,6 +353,7 @@ void AddressTrackerLinux::HandleMessage(const char* bu
                                         bool* address_changed,
                                         bool* link_changed,
                                         bool* tunnel_changed) {
+#if !defined(OS_FREEBSD)
   DCHECK(buffer);
   // Note that NLMSG_NEXT decrements |length| to reflect the number of bytes
   // remaining in |buffer|.
@@ -460,6 +466,10 @@ void AddressTrackerLinux::HandleMessage(const char* bu
         break;
     }
   }
+#else  // !OS_FREEBSD
+  NOTIMPLEMENTED();
+  AbortAndForceOnline();
+#endif // !OS_FREEBSD
 }
 
 void AddressTrackerLinux::OnFileCanReadWithoutBlocking() {
@@ -487,31 +497,7 @@ bool AddressTrackerLinux::IsTunnelInterfaceName(const 
 }
 
 void AddressTrackerLinux::UpdateCurrentConnectionType() {
-  AddressTrackerLinux::AddressMap address_map = GetAddressMap();
-  std::unordered_set<int> online_links = GetOnlineLinks();
-
-  // Strip out tunnel interfaces from online_links
-  for (auto it = online_links.cbegin(); it != online_links.cend();) {
-    if (IsTunnelInterface(*it)) {
-      it = online_links.erase(it);
-    } else {
-      ++it;
-    }
-  }
-
-  NetworkInterfaceList networks;
-  NetworkChangeNotifier::ConnectionType type =
-      NetworkChangeNotifier::CONNECTION_NONE;
-  if (GetNetworkListImpl(&networks, 0, online_links, address_map,
-                         get_interface_name_)) {
-    type = NetworkChangeNotifier::ConnectionTypeFromInterfaceList(networks);
-  } else {
-    type = online_links.empty() ? NetworkChangeNotifier::CONNECTION_NONE
-                                : NetworkChangeNotifier::CONNECTION_UNKNOWN;
-  }
-
-  AddressTrackerAutoLock lock(*this, connection_type_lock_);
-  current_connection_type_ = type;
+  NOTIMPLEMENTED();
 }
 
 int AddressTrackerLinux::GetThreadsWaitingForConnectionTypeInitForTesting() {
