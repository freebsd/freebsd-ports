--- net/base/address_tracker_linux.cc.orig	2019-04-30 22:22:54 UTC
+++ net/base/address_tracker_linux.cc
@@ -21,96 +21,10 @@
 namespace net {
 namespace internal {
 
-namespace {
-
-// Some kernel functions such as wireless_send_event and rtnetlink_ifinfo_prep
-// may send spurious messages over rtnetlink. RTM_NEWLINK messages where
-// ifi_change == 0 and rta_type == IFLA_WIRELESS should be ignored.
-bool IgnoreWirelessChange(const struct nlmsghdr* header,
-                          const struct ifinfomsg* msg) {
-  size_t length = IFLA_PAYLOAD(header);
-  for (const struct rtattr* attr = IFLA_RTA(msg); RTA_OK(attr, length);
-       attr = RTA_NEXT(attr, length)) {
-    if (attr->rta_type == IFLA_WIRELESS && msg->ifi_change == 0)
-      return true;
-  }
-  return false;
-}
-
-// Retrieves address from NETLINK address message.
-// Sets |really_deprecated| for IPv6 addresses with preferred lifetimes of 0.
-bool GetAddress(const struct nlmsghdr* header,
-                IPAddress* out,
-                bool* really_deprecated) {
-  if (really_deprecated)
-    *really_deprecated = false;
-  const struct ifaddrmsg* msg =
-      reinterpret_cast<struct ifaddrmsg*>(NLMSG_DATA(header));
-  size_t address_length = 0;
-  switch (msg->ifa_family) {
-    case AF_INET:
-      address_length = IPAddress::kIPv4AddressSize;
-      break;
-    case AF_INET6:
-      address_length = IPAddress::kIPv6AddressSize;
-      break;
-    default:
-      // Unknown family.
-      return false;
-  }
-  // Use IFA_ADDRESS unless IFA_LOCAL is present. This behavior here is based on
-  // getaddrinfo in glibc (check_pf.c). Judging from kernel implementation of
-  // NETLINK, IPv4 addresses have only the IFA_ADDRESS attribute, while IPv6
-  // have the IFA_LOCAL attribute.
-  uint8_t* address = NULL;
-  uint8_t* local = NULL;
-  size_t length = IFA_PAYLOAD(header);
-  for (const struct rtattr* attr =
-           reinterpret_cast<const struct rtattr*>(IFA_RTA(msg));
-       RTA_OK(attr, length);
-       attr = RTA_NEXT(attr, length)) {
-    switch (attr->rta_type) {
-      case IFA_ADDRESS:
-        DCHECK_GE(RTA_PAYLOAD(attr), address_length);
-        address = reinterpret_cast<uint8_t*>(RTA_DATA(attr));
-        break;
-      case IFA_LOCAL:
-        DCHECK_GE(RTA_PAYLOAD(attr), address_length);
-        local = reinterpret_cast<uint8_t*>(RTA_DATA(attr));
-        break;
-      case IFA_CACHEINFO: {
-        const struct ifa_cacheinfo *cache_info =
-            reinterpret_cast<const struct ifa_cacheinfo*>(RTA_DATA(attr));
-        if (really_deprecated)
-          *really_deprecated = (cache_info->ifa_prefered == 0);
-      } break;
-      default:
-        break;
-    }
-  }
-  if (local)
-    address = local;
-  if (!address)
-    return false;
-  *out = IPAddress(address, address_length);
-  return true;
-}
-
-}  // namespace
-
 // static
 char* AddressTrackerLinux::GetInterfaceName(int interface_index, char* buf) {
-  memset(buf, 0, IFNAMSIZ);
-  base::ScopedFD ioctl_socket = GetSocketForIoctl();
-  if (!ioctl_socket.is_valid())
-    return buf;
-
-  struct ifreq ifr = {};
-  ifr.ifr_ifindex = interface_index;
-
-  if (ioctl(ioctl_socket.get(), SIOCGIFNAME, &ifr) == 0)
-    strncpy(buf, ifr.ifr_name, IFNAMSIZ - 1);
-  return buf;
+  NOTIMPLEMENTED();
+  return NULL;
 }
 
 AddressTrackerLinux::AddressTrackerLinux()
@@ -151,6 +65,7 @@ AddressTrackerLinux::~AddressTrackerLinux() {
 }
 
 void AddressTrackerLinux::Init() {
+#if !defined(OS_FREEBSD)
   netlink_fd_.reset(socket(AF_NETLINK, SOCK_RAW, NETLINK_ROUTE));
   if (!netlink_fd_.is_valid()) {
     PLOG(ERROR) << "Could not create NETLINK socket";
@@ -239,6 +154,10 @@ void AddressTrackerLinux::Init() {
       return;
     }
   }
+#else  // !OS_FREEBSD
+  NOTIMPLEMENTED();
+  AbortAndForceOnline();
+#endif // !OS_FREEBSD
 }
 
 void AddressTrackerLinux::AbortAndForceOnline() {
@@ -250,25 +169,6 @@ void AddressTrackerLinux::AbortAndForceOnline() {
   connection_type_initialized_cv_.Broadcast();
 }
 
-AddressTrackerLinux::AddressMap AddressTrackerLinux::GetAddressMap() const {
-  AddressTrackerAutoLock lock(*this, address_map_lock_);
-  return address_map_;
-}
-
-std::unordered_set<int> AddressTrackerLinux::GetOnlineLinks() const {
-  AddressTrackerAutoLock lock(*this, online_links_lock_);
-  return online_links_;
-}
-
-bool AddressTrackerLinux::IsInterfaceIgnored(int interface_index) const {
-  if (ignored_interfaces_.empty())
-    return false;
-
-  char buf[IFNAMSIZ] = {0};
-  const char* interface_name = get_interface_name_(interface_index, buf);
-  return ignored_interfaces_.find(interface_name) != ignored_interfaces_.end();
-}
-
 NetworkChangeNotifier::ConnectionType
 AddressTrackerLinux::GetCurrentConnectionType() {
   // http://crbug.com/125097
@@ -326,102 +226,7 @@ void AddressTrackerLinux::HandleMessage(char* buffer,
                                         bool* address_changed,
                                         bool* link_changed,
                                         bool* tunnel_changed) {
-  DCHECK(buffer);
-  for (struct nlmsghdr* header = reinterpret_cast<struct nlmsghdr*>(buffer);
-       NLMSG_OK(header, length);
-       header = NLMSG_NEXT(header, length)) {
-    switch (header->nlmsg_type) {
-      case NLMSG_DONE:
-        return;
-      case NLMSG_ERROR: {
-        const struct nlmsgerr* msg =
-            reinterpret_cast<struct nlmsgerr*>(NLMSG_DATA(header));
-        LOG(ERROR) << "Unexpected netlink error " << msg->error << ".";
-      } return;
-      case RTM_NEWADDR: {
-        IPAddress address;
-        bool really_deprecated;
-        struct ifaddrmsg* msg =
-            reinterpret_cast<struct ifaddrmsg*>(NLMSG_DATA(header));
-        if (IsInterfaceIgnored(msg->ifa_index))
-          break;
-        if (GetAddress(header, &address, &really_deprecated)) {
-          AddressTrackerAutoLock lock(*this, address_map_lock_);
-          // Routers may frequently (every few seconds) output the IPv6 ULA
-          // prefix which can cause the linux kernel to frequently output two
-          // back-to-back messages, one without the deprecated flag and one with
-          // the deprecated flag but both with preferred lifetimes of 0. Avoid
-          // interpretting this as an actual change by canonicalizing the two
-          // messages by setting the deprecated flag based on the preferred
-          // lifetime also.  http://crbug.com/268042
-          if (really_deprecated)
-            msg->ifa_flags |= IFA_F_DEPRECATED;
-          // Only indicate change if the address is new or ifaddrmsg info has
-          // changed.
-          auto it = address_map_.find(address);
-          if (it == address_map_.end()) {
-            address_map_.insert(it, std::make_pair(address, *msg));
-            *address_changed = true;
-          } else if (memcmp(&it->second, msg, sizeof(*msg))) {
-            it->second = *msg;
-            *address_changed = true;
-          }
-        }
-      } break;
-      case RTM_DELADDR: {
-        IPAddress address;
-        const struct ifaddrmsg* msg =
-            reinterpret_cast<struct ifaddrmsg*>(NLMSG_DATA(header));
-        if (IsInterfaceIgnored(msg->ifa_index))
-          break;
-        if (GetAddress(header, &address, NULL)) {
-          AddressTrackerAutoLock lock(*this, address_map_lock_);
-          if (address_map_.erase(address))
-            *address_changed = true;
-        }
-      } break;
-      case RTM_NEWLINK: {
-        const struct ifinfomsg* msg =
-            reinterpret_cast<struct ifinfomsg*>(NLMSG_DATA(header));
-        if (IsInterfaceIgnored(msg->ifi_index))
-          break;
-        if (IgnoreWirelessChange(header, msg)) {
-          VLOG(2) << "Ignoring RTM_NEWLINK message";
-          break;
-        }
-        if (!(msg->ifi_flags & IFF_LOOPBACK) && (msg->ifi_flags & IFF_UP) &&
-            (msg->ifi_flags & IFF_LOWER_UP) && (msg->ifi_flags & IFF_RUNNING)) {
-          AddressTrackerAutoLock lock(*this, online_links_lock_);
-          if (online_links_.insert(msg->ifi_index).second) {
-            *link_changed = true;
-            if (IsTunnelInterface(msg->ifi_index))
-              *tunnel_changed = true;
-          }
-        } else {
-          AddressTrackerAutoLock lock(*this, online_links_lock_);
-          if (online_links_.erase(msg->ifi_index)) {
-            *link_changed = true;
-            if (IsTunnelInterface(msg->ifi_index))
-              *tunnel_changed = true;
-          }
-        }
-      } break;
-      case RTM_DELLINK: {
-        const struct ifinfomsg* msg =
-            reinterpret_cast<struct ifinfomsg*>(NLMSG_DATA(header));
-        if (IsInterfaceIgnored(msg->ifi_index))
-          break;
-        AddressTrackerAutoLock lock(*this, online_links_lock_);
-        if (online_links_.erase(msg->ifi_index)) {
-          *link_changed = true;
-          if (IsTunnelInterface(msg->ifi_index))
-            *tunnel_changed = true;
-        }
-      } break;
-      default:
-        break;
-    }
-  }
+  NOTIMPLEMENTED();
 }
 
 void AddressTrackerLinux::OnFileCanReadWithoutBlocking(int fd) {
@@ -452,31 +257,7 @@ bool AddressTrackerLinux::IsTunnelInterfaceName(const 
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
 
 int AddressTrackerLinux::GetThreadsWaitingForConnectionTypeInitForTesting()
