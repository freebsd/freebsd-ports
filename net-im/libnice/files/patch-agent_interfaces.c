--- agent/interfaces.c.orig	2010-07-20 17:54:40.000000000 -0400
+++ agent/interfaces.c	2010-07-24 20:24:19.000000000 -0400
@@ -46,6 +46,7 @@
  #include <ifaddrs.h>
 #endif
 
+#include <netinet/in.h>
 #include <net/if.h>
 #include <net/if_arp.h>
 #include <arpa/inet.h>
@@ -198,7 +199,7 @@ nice_interfaces_get_local_ips (gboolean 
       struct sockaddr_in6 *sa6 = (struct sockaddr_in6 *)ifa->ifa_addr;
 
       /* Skip link-local addresses, they require a scope */
-      if (IN6_IS_ADDR_LINKLOCAL (sa6->sin6_addr.s6_addr))
+      if (IN6_IS_ADDR_LINKLOCAL (&sa6->sin6_addr))
         continue;
 
       if (inet_ntop (AF_INET6, &sa6->sin6_addr, addr_as_string,
