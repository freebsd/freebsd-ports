--- net/base/network_interfaces_freebsd.h.orig	2017-07-04 23:05:05.313339000 +0200
+++ net/base/network_interfaces_freebsd.h	2017-07-04 23:04:51.039635000 +0200
@@ -0,0 +1,44 @@
+// Copyright (c) 2014 The Chromium Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#ifndef NET_BASE_NETWORK_INTERFACES_FREEBSD_H_
+#define NET_BASE_NETWORK_INTERFACES_FREEBSD_H_
+
+// This file is only used to expose some of the internals
+// of network_interfaces_mac.cc to tests.
+
+#include <sys/socket.h>
+
+#include "base/macros.h"
+#include "net/base/net_export.h"
+#include "net/base/network_interfaces.h"
+
+struct ifaddrs;
+struct sockaddr;
+
+namespace net {
+namespace internal {
+
+class NET_EXPORT IPAttributesGetterFreeBSD {
+ public:
+  IPAttributesGetterFreeBSD() {}
+  virtual ~IPAttributesGetterFreeBSD() {}
+  virtual bool IsInitialized() const = 0;
+  virtual bool GetIPAttributes(const char* ifname,
+                               const sockaddr* sock_addr,
+                               int* native_attributes) = 0;
+
+ private:
+  DISALLOW_COPY_AND_ASSIGN(IPAttributesGetterFreeBSD);
+};
+
+NET_EXPORT bool GetNetworkListImpl(NetworkInterfaceList* networks,
+                                   int policy,
+                                   const ifaddrs* interfaces,
+                                   IPAttributesGetterFreeBSD* ip_attributes_getter);
+
+}  // namespace internal
+}  // namespace net
+
+#endif  // NET_BASE_NETWORK_INTERFACES_FREEBSD_H_
