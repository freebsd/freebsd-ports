--- chrome/browser/media/router/discovery/discovery_network_list_wifi_linux.cc.orig	2025-02-20 09:59:21 UTC
+++ chrome/browser/media/router/discovery/discovery_network_list_wifi_linux.cc
@@ -4,7 +4,11 @@
 
 #include "chrome/browser/media/router/discovery/discovery_network_list_wifi.h"
 
+#include "build/build_config.h"
+
+#if !BUILDFLAG(IS_BSD)
 #include <linux/wireless.h>
+#endif
 #include <string.h>
 #include <sys/ioctl.h>
 #include <sys/socket.h>
@@ -19,6 +23,7 @@ namespace media_router {
 bool MaybeGetWifiSSID(const std::string& if_name, std::string* ssid_out) {
   DCHECK(ssid_out);
 
+#if !BUILDFLAG(IS_BSD)
   base::ScopedFD ioctl_socket(socket(AF_INET, SOCK_DGRAM, 0));
   if (!ioctl_socket.is_valid()) {
     // AF_INET is for IPv4, so it may fail for IPv6-only hosts even when there
@@ -41,6 +46,7 @@ bool MaybeGetWifiSSID(const std::string& if_name, std:
     ssid_out->assign(ssid);
     return true;
   }
+#endif
   return false;
 }
 
