--- boreas/util.c	2020-12-30 23:52:07.849996000 -0500
+++ boreas/util.c	2020-12-31 01:36:37.600382000 -0500
@@ -21,12 +21,20 @@
 
 #include "../base/networking.h" /* for range_t */
 
+#include <stdio.h>
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <errno.h>
 #include <glib.h>
 #include <ifaddrs.h> /* for getifaddrs() */
 #include <net/ethernet.h>
 #include <net/if.h>           /* for if_nametoindex() */
-#include <netpacket/packet.h> /* for sockaddr_ll */
+#ifdef AF_LINK
+#   include <net/if_dl.h>
+#endif
+#ifdef AF_PACKET
+#   include <netpacket/packet.h>
+#endif
 #include <stdlib.h>
 #include <string.h>
 #include <sys/socket.h>
@@ -109,22 +117,22 @@
     {
       for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next)
         {
-          if ((ifa->ifa_addr) && (ifa->ifa_addr->sa_family == AF_PACKET)
+          if ((ifa->ifa_addr) && (ifa->ifa_addr->sa_family == AF_LINK)
               && !(ifa->ifa_flags & (IFF_LOOPBACK)))
             {
               if (interface_provided)
                 {
                   if (g_strcmp0 (interface, ifa->ifa_name) == 0)
                     {
-                      struct sockaddr_ll *s =
-                        (struct sockaddr_ll *) ifa->ifa_addr;
-                      memcpy (mac, s->sll_addr, 6 * sizeof (uint8_t));
+                      struct sockaddr_dl *s =
+                        (struct sockaddr_dl *) ifa->ifa_addr;
+                      memcpy (mac, s->sdl_data, 6 * sizeof (uint8_t));
                     }
                 }
               else
                 {
-                  struct sockaddr_ll *s = (struct sockaddr_ll *) ifa->ifa_addr;
-                  memcpy (mac, s->sll_addr, 6 * sizeof (uint8_t));
+                  struct sockaddr_dl *s = (struct sockaddr_dl *) ifa->ifa_addr;
+                  memcpy (mac, s->sdl_data, 6 * sizeof (uint8_t));
                 }
             }
         }
@@ -508,7 +516,7 @@
       break;
     case ARPV4:
       {
-        soc = socket (PF_PACKET, SOCK_RAW, htons (ETH_P_ALL));
+        soc = socket (PF_LINK, SOCK_RAW, 0);
         if (soc < 0)
           {
             g_warning ("%s: failed to open ARPV4 socket: %s", __func__,
