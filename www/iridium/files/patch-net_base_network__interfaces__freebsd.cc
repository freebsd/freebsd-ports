--- net/base/network_interfaces_freebsd.cc.orig	2017-07-05 18:08:44.779023000 +0200
+++ net/base/network_interfaces_freebsd.cc	2017-07-05 22:03:18.679624000 +0200
@@ -0,0 +1,240 @@
+// Copyright (c) 2014 The Chromium Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#include "net/base/network_interfaces_freebsd.h"
+
+#include <ifaddrs.h>
+#include <net/if.h>
+#include <netinet/in.h>
+#include <sys/types.h>
+#include <net/if_media.h>
+#include <net/if_var.h>
+#include <netinet/in_var.h>
+#include <netinet6/in6_var.h>
+#include <sys/ioctl.h>
+
+#include <memory>
+#include <set>
+
+#include "base/files/file_path.h"
+#include "base/logging.h"
+#include "base/strings/string_number_conversions.h"
+#include "base/strings/string_tokenizer.h"
+#include "base/strings/string_util.h"
+#include "base/threading/thread_restrictions.h"
+#include "net/base/escape.h"
+#include "net/base/ip_endpoint.h"
+#include "net/base/net_errors.h"
+#include "net/base/network_interfaces_posix.h"
+#include "url/gurl.h"
+
+namespace net {
+
+namespace {
+
+// FreeBSD implementation of IPAttributesGetterFreeBSD which calls ioctl on socket to
+// retrieve IP attributes.
+class IPAttributesGetterFreeBSDImpl : public internal::IPAttributesGetterFreeBSD {
+ public:
+  IPAttributesGetterFreeBSDImpl();
+  ~IPAttributesGetterFreeBSDImpl() override;
+  bool IsInitialized() const override;
+  bool GetIPAttributes(const char* ifname,
+                       const sockaddr* sock_addr,
+                       int* native_attributes) override;
+
+ private:
+  int ioctl_socket_;
+};
+
+IPAttributesGetterFreeBSDImpl::IPAttributesGetterFreeBSDImpl()
+    : ioctl_socket_(socket(AF_INET6, SOCK_DGRAM, 0)) {
+  DCHECK_GE(ioctl_socket_, 0);
+}
+
+bool IPAttributesGetterFreeBSDImpl::IsInitialized() const {
+  return ioctl_socket_ >= 0;
+}
+
+IPAttributesGetterFreeBSDImpl::~IPAttributesGetterFreeBSDImpl() {
+  if (ioctl_socket_ >= 0) {
+    close(ioctl_socket_);
+  }
+}
+
+bool IPAttributesGetterFreeBSDImpl::GetIPAttributes(const char* ifname,
+                                                const sockaddr* sock_addr,
+                                                int* native_attributes) {
+  struct in6_ifreq ifr = {};
+  strncpy(ifr.ifr_name, ifname, sizeof(ifr.ifr_name) - 1);
+  memcpy(&ifr.ifr_ifru.ifru_addr, sock_addr, sock_addr->sa_len);
+  int rv = ioctl(ioctl_socket_, SIOCGIFAFLAG_IN6, &ifr);
+  if (rv >= 0) {
+    *native_attributes = ifr.ifr_ifru.ifru_flags;
+  }
+  return (rv >= 0);
+}
+
+// When returning true, the platform native IPv6 address attributes were
+// successfully converted to net IP address attributes. Otherwise, returning
+// false and the caller should drop the IP address which can't be used by the
+// application layer.
+bool TryConvertNativeToNetIPAttributes(int native_attributes,
+                                       int* net_attributes) {
+  // For FreeBSD, we disallow addresses with attributes IN6_IFF_ANYCASE,
+  // IN6_IFF_DUPLICATED, IN6_IFF_TENTATIVE, and IN6_IFF_DETACHED as these are
+  // still progressing through duplicated address detection (DAD) or are not
+  // suitable to be used in an one-to-one communication and shouldn't be used
+  // by the application layer.
+  if (native_attributes & (IN6_IFF_ANYCAST | IN6_IFF_DUPLICATED |
+                           IN6_IFF_TENTATIVE | IN6_IFF_DETACHED)) {
+    return false;
+  }
+
+  if (native_attributes & IN6_IFF_DEPRECATED) {
+    *net_attributes |= IP_ADDRESS_ATTRIBUTE_DEPRECATED;
+  }
+
+  return true;
+}
+
+NetworkChangeNotifier::ConnectionType GetNetworkInterfaceType(
+    int addr_family,
+    const std::string& interface_name) {
+  NetworkChangeNotifier::ConnectionType type =
+      NetworkChangeNotifier::CONNECTION_UNKNOWN;
+
+  struct ifmediareq ifmr = {};
+  strncpy(ifmr.ifm_name, interface_name.c_str(), sizeof(ifmr.ifm_name) - 1);
+
+  int s = socket(addr_family, SOCK_DGRAM, 0);
+  if (s == -1) {
+    return type;
+  }
+
+  if (ioctl(s, SIOCGIFMEDIA, &ifmr) != -1) {
+    if (ifmr.ifm_current & IFM_IEEE80211) {
+      type = NetworkChangeNotifier::CONNECTION_WIFI;
+    } else if (ifmr.ifm_current & IFM_ETHER) {
+      type = NetworkChangeNotifier::CONNECTION_ETHERNET;
+    }
+  }
+  close(s);
+  return type;
+}
+
+}  // namespace
+
+namespace internal {
+
+bool GetNetworkListImpl(NetworkInterfaceList* networks,
+                        int policy,
+                        const ifaddrs* interfaces,
+                        IPAttributesGetterFreeBSD* ip_attributes_getter) {
+  // Enumerate the addresses assigned to network interfaces which are up.
+  for (const ifaddrs* interface = interfaces; interface != NULL;
+       interface = interface->ifa_next) {
+    // Skip loopback interfaces, and ones which are down.
+    if (!(IFF_RUNNING & interface->ifa_flags))
+      continue;
+    if (IFF_LOOPBACK & interface->ifa_flags)
+      continue;
+    // Skip interfaces with no address configured.
+    struct sockaddr* addr = interface->ifa_addr;
+    if (!addr)
+      continue;
+
+    // Skip unspecified addresses (i.e. made of zeroes) and loopback addresses
+    // configured on non-loopback interfaces.
+    if (IsLoopbackOrUnspecifiedAddress(addr))
+      continue;
+
+    const std::string& name = interface->ifa_name;
+    // Filter out VMware interfaces, typically named vmnet1 and vmnet8.
+    if (ShouldIgnoreInterface(name, policy)) {
+      continue;
+    }
+
+    NetworkChangeNotifier::ConnectionType connection_type =
+        NetworkChangeNotifier::CONNECTION_UNKNOWN;
+
+    int ip_attributes = IP_ADDRESS_ATTRIBUTE_NONE;
+
+    // Retrieve native ip attributes and convert to net version if a getter is
+    // given.
+    if (ip_attributes_getter && ip_attributes_getter->IsInitialized()) {
+      int native_attributes = 0;
+      if (addr->sa_family == AF_INET6 &&
+          ip_attributes_getter->GetIPAttributes(
+              interface->ifa_name, interface->ifa_addr, &native_attributes)) {
+        if (!TryConvertNativeToNetIPAttributes(native_attributes,
+                                               &ip_attributes)) {
+          continue;
+        }
+      }
+    }
+
+    connection_type = GetNetworkInterfaceType(addr->sa_family, name);
+
+    IPEndPoint address;
+
+    int addr_size = 0;
+    if (addr->sa_family == AF_INET6) {
+      addr_size = sizeof(sockaddr_in6);
+    } else if (addr->sa_family == AF_INET) {
+      addr_size = sizeof(sockaddr_in);
+    }
+
+    if (address.FromSockAddr(addr, addr_size)) {
+      uint8_t prefix_length = 0;
+      if (interface->ifa_netmask) {
+        // If not otherwise set, assume the same sa_family as ifa_addr.
+        if (interface->ifa_netmask->sa_family == 0) {
+          interface->ifa_netmask->sa_family = addr->sa_family;
+        }
+        IPEndPoint netmask;
+        if (netmask.FromSockAddr(interface->ifa_netmask, addr_size)) {
+          prefix_length = MaskPrefixLength(netmask.address());
+        }
+      }
+      networks->push_back(NetworkInterface(
+          name, name, if_nametoindex(name.c_str()), connection_type,
+          address.address(), prefix_length, ip_attributes));
+    }
+  }
+
+  return true;
+}
+
+}  // namespace internal
+
+bool GetNetworkList(NetworkInterfaceList* networks, int policy) {
+  if (networks == NULL)
+    return false;
+
+  // getifaddrs() may require IO operations.
+  base::AssertBlockingAllowed();
+
+  ifaddrs* interfaces;
+  if (getifaddrs(&interfaces) < 0) {
+    PLOG(ERROR) << "getifaddrs";
+    return false;
+  }
+
+  std::unique_ptr<internal::IPAttributesGetterFreeBSD> ip_attributes_getter;
+
+  ip_attributes_getter.reset(new IPAttributesGetterFreeBSDImpl());
+
+  bool result = internal::GetNetworkListImpl(networks, policy, interfaces,
+                                             ip_attributes_getter.get());
+  freeifaddrs(interfaces);
+  return result;
+}
+
+std::string GetWifiSSID() {
+  NOTIMPLEMENTED();
+  return "";
+}
+
+}  // namespace net
