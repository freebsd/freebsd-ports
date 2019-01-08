--- chrome/browser/apps/platform_apps/api/music_manager_private/device_id_linux.cc.orig	2018-12-05 14:44:06.182927000 +0100
+++ chrome/browser/apps/platform_apps/api/music_manager_private/device_id_linux.cc	2018-12-05 15:28:09.650594000 +0100
@@ -4,6 +4,11 @@
 
 #include "chrome/browser/apps/platform_apps/api/music_manager_private/device_id.h"
 
+#if defined(OS_FREEBSD)
+#include <sys/types.h>
+#include <net/if_dl.h>
+#endif
+
 #include <ifaddrs.h>
 #include <net/if.h>
 #include <stddef.h>
@@ -104,9 +109,36 @@
                         const char* const prefixes[],
                         size_t prefixes_count) {
     const int MAC_LENGTH = 6;
+#if defined(OS_FREEBSD)
+    struct ifaddrs *ifap, *ifinfo;
+#else
     struct ifreq ifinfo;
+#endif
 
     memset(&ifinfo, 0, sizeof(ifinfo));
+
+#if defined(OS_FREEBSD)
+    int result = getifaddrs(&ifap);
+
+    if (result != 0)
+      return true;
+
+    result = 1; // no MAC found yet
+
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
+
+    strncpy(mac_address, (const char*)LLADDR((struct sockaddr_dl*)ifinfo->ifa_addr), sizeof(mac_address));
+#else
     strncpy(ifinfo.ifr_name, ifaddr->ifa_name, sizeof(ifinfo.ifr_name) - 1);
 
     int sd = socket(AF_INET, SOCK_DGRAM, 0);
@@ -118,11 +150,18 @@
 
     const char* mac_address =
         static_cast<const char*>(ifinfo.ifr_hwaddr.sa_data);
+#endif
+
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
