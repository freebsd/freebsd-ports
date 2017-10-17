--- chrome/browser/media/router/discovery/discovery_network_list_wifi_linux.cc.orig	2017-09-05 21:05:13.000000000 +0200
+++ chrome/browser/media/router/discovery/discovery_network_list_wifi_linux.cc	2017-09-10 03:43:00.933828000 +0200
@@ -9,8 +9,6 @@
 #include <sys/socket.h>
 #include <sys/types.h>
 
-#include <linux/wireless.h>
-
 #include "base/files/scoped_file.h"
 #include "base/logging.h"
 #include "net/base/network_interfaces_linux.h"
@@ -18,6 +16,7 @@
 bool MaybeGetWifiSSID(const std::string& if_name, std::string* ssid_out) {
   DCHECK(ssid_out);
 
+#if !defined(OS_BSD)
   base::ScopedFD ioctl_socket(socket(AF_INET, SOCK_DGRAM, 0));
   if (!ioctl_socket.is_valid())
     return false;
@@ -34,5 +33,6 @@
     ssid_out->assign(ssid);
     return true;
   }
+#endif
   return false;
 }
