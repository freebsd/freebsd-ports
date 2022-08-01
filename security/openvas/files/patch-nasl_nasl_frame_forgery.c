--- nasl/nasl_frame_forgery.c	2022-04-12 18:39:11.965973000 -0500
+++ nasl/nasl_frame_forgery.c	2022-04-12 22:42:28.026027000 -0500
@@ -33,12 +33,17 @@
 
 #include <errno.h>
 #include <gvm/base/networking.h>
+#if defined(linux)
 #include <linux/if_packet.h>
+#include <netinet/ether.h>
+#endif
 #include <net/ethernet.h>
 #include <net/if.h>
 #include <net/if_arp.h>
-#include <netinet/ether.h>
+#include <net/if_dl.h>
 #include <netinet/if_ether.h>
+#include <netinet/in.h>
+#include <arpa/inet.h>
 #include <stdint.h>
 #include <stdio.h>
 #include <stdlib.h>
@@ -51,6 +56,13 @@
  */
 #define G_LOG_DOMAIN "lib  misc"
 
+#if defined(__FreeBSD__)
+#define ETH_ALEN ETHER_ADDR_LEN
+#define ETH_P_ARP ETHERTYPE_ARP
+#define ETH_P_ALL 0x0003
+#define ETH_HLEN ETHER_HDR_LEN
+#endif
+
 struct pseudo_eth_arp
 {
   struct arphdr arp_header;
@@ -63,7 +75,11 @@
 
 struct pseudo_frame
 {
+#if defined(__FreeBSD__)
+  struct ether_header framehdr;
+#else
   struct ethhdr framehdr;
+#endif
   u_char *payload;
 } __attribute__ ((packed));
 
@@ -95,7 +111,23 @@
  * @param[in] ifindex The interface index to be use for capturing.
  * @param[in] ether_dst_addr The dst MAC address.
  */
+
+#if defined(__FreeBSD__)
 static void
+prepare_sockaddr_ll (struct sockaddr_dl *addr, int ifindex,
+                     const u_char *ether_dst_addr)
+{
+  struct sockaddr_dl *sdl = (struct sockaddr_dl *)addr;
+
+  sdl->sdl_family = AF_LINK;
+  sdl->sdl_index = ifindex;
+  sdl->sdl_alen = ETHER_ADDR_LEN;
+  sdl->sdl_type = ETH_P_ALL;
+
+  memcpy (sdl->sdl_data + sdl->sdl_nlen, ether_dst_addr, ETHER_ADDR_LEN);
+}
+#else
+static void
 prepare_sockaddr_ll (struct sockaddr_ll *soc_addr_ll, int ifindex,
                      const u_char *ether_dst_addr)
 {
@@ -105,6 +137,7 @@
   soc_addr_ll->sll_protocol = htons (ETH_P_ALL);
   memcpy (soc_addr_ll->sll_addr, ether_dst_addr, ETHER_ADDR_LEN);
 }
+#endif
 
 /** @brief Prepare message header to be sent with sendmsg().
  *
@@ -113,6 +146,7 @@
  * @param[in] payload The payload, a datalink layer frame with payload
  * @param[in] payload_sz The payload size.
  */
+#if !defined(__FreeBSD__)
 static void
 prepare_message (u_char *msg, struct sockaddr_ll *soc_addr_ll, u_char *payload,
                  int payload_sz)
@@ -135,7 +169,31 @@
   memcpy (msg, (u_char *) message, sizeof (struct msghdr) + payload_sz);
   g_free (message);
 }
+#else
+static void
+prepare_message (u_char *msg, struct sockaddr_dl *soc_addr_dl, u_char *payload,
+                 int payload_sz)
+{
+  struct iovec iov;
+  struct msghdr *message;
 
+  iov.iov_base = payload;
+  iov.iov_len = payload_sz;
+
+  message = g_malloc0 (sizeof (struct msghdr) + payload_sz);
+
+  message->msg_name = soc_addr_dl;
+  message->msg_namelen = sizeof (struct sockaddr_dl);
+  message->msg_iov = &iov;
+  message->msg_iovlen = 1;
+  message->msg_control = 0;
+  message->msg_controllen = 0;
+
+  memcpy (msg, (u_char *) message, sizeof (struct msghdr) + payload_sz);
+  g_free (message);
+}
+#endif
+
 /** @brief Send a frame and listen to the answer
  *
  * @param[in]frame         The frame to be sent.
@@ -163,7 +221,11 @@
   int answer_sz = -1;
 
   // Create the raw socket
+#if defined(__FreeBSD__)
+  soc = socket (AF_INET, SOCK_RAW, htons (ETH_P_ALL));
+#else
   soc = socket (AF_PACKET, SOCK_RAW, htons (ETH_P_ALL));
+#endif
   if (soc == -1)
     {
       g_debug ("%s: %s", __func__, strerror (errno));
@@ -181,8 +243,12 @@
   u_char dst_haddr[ETHER_ADDR_LEN];
   memcpy (&dst_haddr, (struct pseudo_frame *) frame, ETHER_ADDR_LEN);
 
+#if defined(__FreeBSD__)
+  struct sockaddr_dl soc_addr;
+#else
   struct sockaddr_ll soc_addr;
-  memset (&soc_addr, '\0', sizeof (struct sockaddr_ll));
+#endif
+  memset (&soc_addr, '\0', sizeof (struct sockaddr_dl));
   prepare_sockaddr_ll (&soc_addr, ifindex, dst_haddr);
 
   /* Init capture */
@@ -193,7 +259,7 @@
           struct in_addr sin, this_host;
           memset (&sin, '\0', sizeof (struct in_addr));
           memset (&this_host, '\0', sizeof (struct in_addr));
-          sin.s_addr = ipaddr->s6_addr32[3];
+          sin.s_addr = ipaddr->s6_addr[12];
           bpf = init_capture_device (sin, this_host, filter);
         }
       else
@@ -249,10 +315,15 @@
 
   *frame = (struct pseudo_frame *) g_malloc0 (sizeof (struct pseudo_frame)
                                               + payload_sz);
-
+#if defined(__FreeBSD__)
+  memcpy ((*frame)->framehdr.ether_dhost, ether_dst_addr, ETHER_ADDR_LEN);
+  memcpy ((*frame)->framehdr.ether_shost, ether_src_addr, ETHER_ADDR_LEN);
+  (*frame)->framehdr.ether_type = htons (ether_proto);
+#else
   memcpy ((*frame)->framehdr.h_dest, ether_dst_addr, ETHER_ADDR_LEN);
   memcpy ((*frame)->framehdr.h_source, ether_src_addr, ETHER_ADDR_LEN);
   (*frame)->framehdr.h_proto = htons (ether_proto);
+#endif
   (*frame)->payload = payload;
 
   frame_sz = ETH_HLEN + payload_sz;
@@ -416,21 +487,24 @@
   strncpy (ifr.ifr_name, if_name, sizeof (ifr.ifr_name) - 1);
   g_free (if_name);
   ifr.ifr_name[sizeof (ifr.ifr_name) - 1] = '\0';
-
+#if defined(__FreeBSD__)
+  sock = socket(AF_INET, SOCK_DGRAM, 0);
+#else
   sock = socket (PF_INET, SOCK_STREAM, 0);
+#endif
   if (-1 == sock)
     {
       perror ("socket() ");
       return -1;
     }
 
-  if (-1 == ioctl (sock, SIOCGIFHWADDR, &ifr))
+  if (-1 == ioctl (sock, SIOCGIFCONF, &ifr))
     {
-      g_debug ("%s: ioctl(SIOCGIFHWADDR)", __func__);
+      g_debug ("%s: ioctl(SIOCGIFCONF)", __func__);
       return -1;
     }
 
-  memcpy (mac, (u_char *) ifr.ifr_hwaddr.sa_data, ETHER_ADDR_LEN);
+  memcpy (mac, (u_char *) ifr.ifr_data, ETHER_ADDR_LEN);
   close (sock);
 
   return 0;
@@ -504,7 +578,7 @@
     return retc;
 
   memset (&dst_inaddr, '\0', sizeof (struct in_addr));
-  dst_inaddr.s_addr = dst->s6_addr32[3];
+  dst_inaddr.s_addr = dst->s6_addr[12];
   routethrough (&dst_inaddr, &src_inaddr);
   ipv4_as_ipv6 (&src_inaddr, &src);
 
