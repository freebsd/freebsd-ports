--- chrome/browser/media/router/discovery/discovery_network_list_wifi_linux.cc.orig	2026-11-19 12:25:27 UTC
+++ chrome/browser/media/router/discovery/discovery_network_list_wifi_linux.cc
@@ -4,7 +4,11 @@
 
 #include "chrome/browser/media/router/discovery/discovery_network_list_wifi.h"
 
+#include "build/build_config.h"
+
+#if !BUILDFLAG(IS_BSD)
 #include <linux/wireless.h>
+#endif
 #include <sys/ioctl.h>
 #include <sys/socket.h>
 #include <sys/types.h>
@@ -17,11 +21,14 @@
 #include "base/files/scoped_file.h"
 #include "base/strings/string_util.h"
 #include "base/strings/string_view_util.h"
+#if !BUILDFLAG(IS_BSD)
 #include "net/base/network_interfaces_linux.h"
+#endif
 
 namespace media_router {
 
 std::optional<std::string> MaybeGetWifiSSID(std::string_view if_name) {
+#if !BUILDFLAG(IS_BSD)
   base::ScopedFD ioctl_socket(socket(AF_INET, SOCK_DGRAM, 0));
   if (!ioctl_socket.is_valid()) {
     // AF_INET is for IPv4, so it may fail for IPv6-only hosts even when there
@@ -46,6 +53,9 @@ std::optional<std::string> MaybeGetWifiSSID(std::strin
     return std::nullopt;
   }
   return std::string(ssid_view);
+#else
+  return std::nullopt;
+#endif
 }
 
 }  // namespace media_router
