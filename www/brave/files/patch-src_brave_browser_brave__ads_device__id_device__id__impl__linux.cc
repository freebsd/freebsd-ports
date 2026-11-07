--- src/brave/browser/brave_ads/device_id/device_id_impl_linux.cc.orig	2026-06-01 00:00:00 UTC
+++ src/brave/browser/brave_ads/device_id/device_id_impl_linux.cc
@@ -12,6 +12,13 @@
 #include <sys/ioctl.h>
 #include <sys/socket.h>
 
+#include "build/build_config.h"
+
+#if BUILDFLAG(IS_BSD)
+#include <net/if_dl.h>
+#include <net/if_types.h>
+#endif
+
 #include <array>
 #include <map>
 #include <string>
@@ -119,6 +126,36 @@
   bool ProcessInterface(struct ifaddrs* ifaddr) {
     bool keep_going = true;
 
+    constexpr size_t kMacLength = 6U;
+
+#if BUILDFLAG(IS_BSD)
+    // FreeBSD has neither SIOCGIFHWADDR nor ifreq::ifr_hwaddr.  It does not
+    // need them: getifaddrs() reports the hardware address itself, in the
+    // AF_LINK entry it emits alongside the address families of every
+    // interface.
+    if (!ifaddr->ifa_addr || ifaddr->ifa_addr->sa_family != AF_LINK) {
+      return keep_going;
+    }
+
+    struct sockaddr_dl* const sdl =
+        reinterpret_cast<struct sockaddr_dl*>(ifaddr->ifa_addr);
+
+    // kNetDeviceNamePrefixes is a list of Linux interface names and says
+    // nothing about a FreeBSD host, whose drivers name interfaces em0, re0,
+    // igb0, vtnet0 and so on -- of those only em0 happens to match.  sdl_type
+    // is the same question asked properly: it keeps the Ethernet-class
+    // interfaces, wlan among them, and drops lo0, tun and bridge.
+    if (sdl->sdl_type != IFT_ETHER || sdl->sdl_alen != kMacLength) {
+      return keep_going;
+    }
+
+    std::array<uint8_t, kMacLength> mac_address_storage;
+    UNSAFE_TODO(memcpy(mac_address_storage.data(), LLADDR(sdl), kMacLength));
+    auto mac_address_bytes = base::as_byte_span(mac_address_storage);
+    if (!is_valid_mac_address_callback_.Run(mac_address_bytes)) {
+      return keep_going;
+    }
+#else
     struct ifreq ifinfo = {};
     UNSAFE_TODO(strncpy(ifinfo.ifr_name, ifaddr->ifa_name,
                         sizeof(ifinfo.ifr_name) - 1));
@@ -131,7 +168,6 @@
       return keep_going;
     }
 
-    constexpr size_t kMacLength = 6U;
     auto mac_address_bytes =
         base::as_byte_span(ifinfo.ifr_hwaddr.sa_data).first<kMacLength>();
     if (!is_valid_mac_address_callback_.Run(mac_address_bytes)) {
@@ -141,6 +177,7 @@
     if (!IsValidPrefix(ifinfo.ifr_name)) {
       return keep_going;
     }
+#endif
 
     keep_going = false;
 
