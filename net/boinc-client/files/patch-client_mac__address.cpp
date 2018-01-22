--- client/mac_address.cpp.orig	2018-01-14 10:07:52 UTC
+++ client/mac_address.cpp
@@ -67,6 +67,10 @@
 #ifdef HAVE_NETINET_ETHER_H
 #include <netinet/ether.h>
 #endif
+#if defined(__FreeBSD__)
+#include <ifaddrs.h>
+#include <net/if_dl.h>
+#endif 
 
 #include "mac_address.h"
 
@@ -262,10 +266,32 @@ int get_mac_address(char* address) {
             return -1;
         }
         hw_addr = (struct ether_addr *)&(item->lifr_lifru.lifru_enaddr);  
+#elif defined(__FreeBSD__)
+    struct ifaddrs *ifap, *ifaptr;
+    unsigned char *ptr;
+
+    if (getifaddrs(&ifap) == 0) {
+        for(ifaptr = ifap; ifaptr != NULL; ifaptr = (ifaptr)->ifa_next) {
+            if (!strcmp((ifaptr)->ifa_name,  item->ifr_name) && (((ifaptr)->ifa_addr)->sa_family == AF_LINK)) {
+                ptr = (unsigned char *)LLADDR((struct sockaddr_dl *)(ifaptr)->ifa_addr);
+                hw_addr = (struct ether_addr *)ptr;
+                break;
+            }
+        }
+    } else {
+        return -1;
+    }
+#else
+	return -1;
 #endif
         strcpy(address, ether_ntoa(hw_addr));
+#if	defined(__FreeBSD__)
+	freeifaddrs(ifap);
+#endif
 #ifdef HAVE_STRUCT_LIFCONF
         if (strstr(item->lifr_name, "eth")) break;
+#elif  defined(__FreeBSD__)
+	break;
 #else
         if (strstr(item->ifr_name, "eth")) break;
 #endif
