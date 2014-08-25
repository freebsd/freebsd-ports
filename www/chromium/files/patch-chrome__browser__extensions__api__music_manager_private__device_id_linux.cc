--- ./chrome/browser/extensions/api/music_manager_private/device_id_linux.cc.orig	2014-08-20 21:01:57.000000000 +0200
+++ ./chrome/browser/extensions/api/music_manager_private/device_id_linux.cc	2014-08-22 15:06:24.000000000 +0200
@@ -4,6 +4,10 @@
 
 #include "chrome/browser/extensions/api/music_manager_private/device_id.h"
 
+#if defined(OS_FREEBSD)
+#include <sys/types.h>
+#include <net/if_dl.h>
+#endif
 #include <sys/socket.h>  // Must be included before ifaddrs.h.
 #include <ifaddrs.h>
 #include <net/if.h>
@@ -102,11 +106,33 @@
                         const char* prefixes[],
                         size_t prefixes_count) {
     const int MAC_LENGTH = 6;
+#if defined(OS_FREEBSD)
+    struct ifaddrs *ifap, *ifinfo;
+#else
     struct ifreq ifinfo;
+#endif
 
     memset(&ifinfo, 0, sizeof(ifinfo));
-    strncpy(ifinfo.ifr_name, ifaddr->ifa_name, sizeof(ifinfo.ifr_name) - 1);
 
+#if defined(OS_FREEBSD)
+    int result = getifaddrs(&ifap);
+    if (result != 0)
+      return true;
+    result = 1; // no MAC found yet
+    for (ifinfo = ifap; ifinfo != NULL; ifinfo = ifinfo->ifa_next) {
+      struct sockaddr* sa = ifinfo->ifa_addr;
+      if (sa->sa_family == AF_LINK &&
+        !strncmp(ifinfo->ifa_name, ifaddr->ifa_name,
+        sizeof(ifinfo->ifa_name) - 1)) { 
+          result = 0;
+	  break;
+      }
+    }
+
+    char mac_address[6];
+    strncpy(mac_address, (const char*)LLADDR((struct sockaddr_dl*)ifinfo->ifa_addr), sizeof(mac_address));
+#else
+    strncpy(ifinfo.ifr_name, ifaddr->ifa_name, sizeof(ifinfo.ifr_name) - 1);
     int sd = socket(AF_INET, SOCK_DGRAM, 0);
     int result = ioctl(sd, SIOCGIFHWADDR, &ifinfo);
     close(sd);
@@ -116,11 +142,17 @@
 
     const char* mac_address =
         static_cast<const char*>(ifinfo.ifr_hwaddr.sa_data);
+#endif
     if (!is_valid_mac_address_.Run(mac_address, MAC_LENGTH))
       return true;
 
+#if defined(OS_FREEBSD)
+    if (!IsValidPrefix(ifinfo->ifa_name, prefixes, prefixes_count))
+      return true;
+#else
     if (!IsValidPrefix(ifinfo.ifr_name, prefixes, prefixes_count))
       return true;
+#endif
 
     // Got one!
     found_mac_address_ =
