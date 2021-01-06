--- base/networking.c	2020-12-30 23:53:55.170376000 -0500
+++ base/networking.c	2020-12-31 00:06:29.941646000 -0500
@@ -30,28 +30,30 @@
 #include <errno.h>     /* for errno, EAFNOSUPPORT */
 #include <glib/gstdio.h>
 #include <ifaddrs.h>    /* for ifaddrs, freeifaddrs, getifaddrs */
+#include <sys/types.h>
 #include <net/if.h>     /* for IFNAMSIZ */
+#include <netinet/in.h>
 #include <stdint.h>     /* for uint32_t, uint8_t */
 #include <stdlib.h>     /* for atoi, strtol */
 #include <string.h>     /* for memcpy, bzero, strchr, strlen, strcmp, strncpy */
 #include <sys/socket.h> /* for AF_INET, AF_INET6, AF_UNSPEC, sockaddr_storage */
 #include <unistd.h>     /* for close */
 
-#ifdef __FreeBSD__
-#include <netinet/in.h>
-#define s6_addr32 __u6_addr.__u6_addr32
-#endif
+//#ifdef __FreeBSD__
+//#include <netinet/in.h>
+//#define s6_addr32 __u6_addr.__u6_addr32
+//#endif
 
 /* Global variables */
 
 /* Source interface name eg. eth1. */
-char global_source_iface[IFNAMSIZ] = {'\0'};
+char global_source_iface[IFNAMSIZ];
 
 /* Source IPv4 address. */
-struct in_addr global_source_addr = {.s_addr = 0};
+struct in_addr global_source_addr;
 
 /* Source IPv6 address. */
-struct in6_addr global_source_addr6 = {.s6_addr32 = {0, 0, 0, 0}};
+struct in6_addr global_source_addr6;
 
 /* Source Interface/Address related functions. */
 
@@ -244,10 +246,19 @@
   if (ip4 == NULL || ip6 == NULL)
     return;
 
-  ip6->s6_addr32[0] = 0;
-  ip6->s6_addr32[1] = 0;
-  ip6->s6_addr32[2] = htonl (0xffff);
-  memcpy (&ip6->s6_addr32[3], ip4, sizeof (struct in_addr));
+  ip6->s6_addr[0] = 0;
+  ip6->s6_addr[1] = 0;
+  ip6->s6_addr[2] = 0;
+  ip6->s6_addr[3] = 0;
+  ip6->s6_addr[4] = 0;
+  ip6->s6_addr[5] = 0;
+  ip6->s6_addr[6] = 0;
+  ip6->s6_addr[7] = 0;
+  ip6->s6_addr[8] = 0;
+  ip6->s6_addr[9] = 0;
+  ip6->s6_addr[10] = 0xff;
+  ip6->s6_addr[11] = 0xff;
+  memcpy (&ip6->s6_addr[12], ip4, sizeof (struct in_addr));
 }
 
 /**
@@ -262,7 +273,7 @@
   if (!addr6)
     return;
   if (IN6_IS_ADDR_V4MAPPED (addr6))
-    inet_ntop (AF_INET, &addr6->s6_addr32[3], str, INET6_ADDRSTRLEN);
+    inet_ntop (AF_INET, &addr6->s6_addr[12], str, INET6_ADDRSTRLEN);
   else
     inet_ntop (AF_INET6, addr6, str, INET6_ADDRSTRLEN);
 }
@@ -808,11 +819,11 @@
       if (IN6_IS_ADDR_V4MAPPED (&addr6))
         {
           /* addr is 0.0.0.0 */
-          if (addr6_p->s6_addr32[3] == 0)
+          if (addr6_p->s6_addr[12] == 0)
             return 1;
 
           /* addr starts with 127.0.0.1 */
-          if ((addr6_p->s6_addr32[3] & htonl (0xFF000000))
+          if ((addr6_p->s6_addr[12] & htonl (0xFF000000))
               == htonl (0x7F000000))
             return 1;
         }
