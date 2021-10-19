--- net/base/address_tracker_linux.cc.orig	2021-09-24 04:26:08 UTC
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
@@ -191,6 +193,7 @@ void AddressTrackerLinux::Init() {
   DCHECK_LT(base::android::BuildInfo::GetInstance()->sdk_int(),
             base::android::SDK_VERSION_P);
 #endif
+#if !defined(OS_FREEBSD)
   netlink_fd_.reset(socket(AF_NETLINK, SOCK_RAW, NETLINK_ROUTE));
   if (!netlink_fd_.is_valid()) {
     PLOG(ERROR) << "Could not create NETLINK socket";
@@ -275,6 +278,10 @@ void AddressTrackerLinux::Init() {
         base::BindRepeating(&AddressTrackerLinux::OnFileCanReadWithoutBlocking,
                             base::Unretained(this)));
   }
+#else  // !OS_FREEBSD
+  NOTIMPLEMENTED();
+  AbortAndForceOnline();
+#endif // !OS_FREEBSD
 }
 
 bool AddressTrackerLinux::DidTrackingInitSucceedForTesting() const {
@@ -291,6 +298,7 @@ void AddressTrackerLinux::AbortAndForceOnline() {
   connection_type_initialized_cv_.Broadcast();
 }
 
+#if !defined(OS_BSD)
 AddressTrackerLinux::AddressMap AddressTrackerLinux::GetAddressMap() const {
   AddressTrackerAutoLock lock(*this, address_map_lock_);
   return address_map_;
@@ -309,6 +317,7 @@ bool AddressTrackerLinux::IsInterfaceIgnored(int inter
   const char* interface_name = get_interface_name_(interface_index, buf);
   return ignored_interfaces_.find(interface_name) != ignored_interfaces_.end();
 }
+#endif // !OS_BSD
 
 NetworkChangeNotifier::ConnectionType
 AddressTrackerLinux::GetCurrentConnectionType() {
@@ -367,6 +376,7 @@ void AddressTrackerLinux::HandleMessage(const char* bu
                                         bool* address_changed,
                                         bool* link_changed,
                                         bool* tunnel_changed) {
+#if !defined(OS_FREEBSD)
   DCHECK(buffer);
   // Note that NLMSG_NEXT decrements |length| to reflect the number of bytes
   // remaining in |buffer|.
@@ -479,6 +489,9 @@ void AddressTrackerLinux::HandleMessage(const char* bu
         break;
     }
   }
+#else  // !OS_FREEBSD
+  NOTIMPLEMENTED();
+#endif // !OS_FREEBSD
 }
 
 void AddressTrackerLinux::OnFileCanReadWithoutBlocking() {
@@ -506,6 +519,7 @@ bool AddressTrackerLinux::IsTunnelInterfaceName(const 
 }
 
 void AddressTrackerLinux::UpdateCurrentConnectionType() {
+#if !defined(OS_FREEBSD)
   AddressTrackerLinux::AddressMap address_map = GetAddressMap();
   std::unordered_set<int> online_links = GetOnlineLinks();
 
@@ -531,6 +545,9 @@ void AddressTrackerLinux::UpdateCurrentConnectionType(
 
   AddressTrackerAutoLock lock(*this, connection_type_lock_);
   current_connection_type_ = type;
+#else
+  NOTIMPLEMENTED();
+#endif
 }
 
 int AddressTrackerLinux::GetThreadsWaitingForConnectionTypeInitForTesting() {
