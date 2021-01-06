--- boreas/ping.c	2020-12-31 00:53:07.116404000 -0500
+++ boreas/ping.c	2020-12-31 02:11:16.635441000 -0500
@@ -29,15 +29,21 @@
 #include <net/ethernet.h>
 #include <net/if.h> /* for if_nametoindex() */
 #include <netinet/icmp6.h>
+#include <sys/types.h>
 #include <netinet/in.h>
+#include <netinet/ip.h>
 #include <netinet/ip6.h>
 #include <netinet/ip_icmp.h>
 #include <netinet/tcp.h>
-#include <netpacket/packet.h> /* for sockaddr_ll */
+#ifdef AF_LINK
+#   include <net/if_dl.h>
+#endif
+#ifdef AF_PACKET
+#   include <netpacket/packet.h>
+#endif
 #include <stdlib.h>
 #include <sys/socket.h>
 #include <sys/time.h>
-#include <sys/types.h>
 #include <unistd.h>
 
 #undef G_LOG_DOMAIN
@@ -138,12 +144,12 @@
   struct icmphdr *icmp;
 
   icmp = (struct icmphdr *) sendbuf;
-  icmp->type = ICMP_ECHO;
-  icmp->code = 0;
+  icmp->icmp_type = ICMP_ECHO;
+  icmp->icmp_code = 0;
 
   len = 8 + datalen;
-  icmp->checksum = 0;
-  icmp->checksum = in_cksum ((u_short *) icmp, len);
+  icmp->icmp_cksum = 0;
+  icmp->icmp_cksum = in_cksum ((u_short *) icmp, len);
 
   memset (&soca, 0, sizeof (soca));
   soca.sin_family = AF_INET;
@@ -197,7 +203,7 @@
     }
   else
     {
-      dst4.s_addr = dst6_p->s6_addr32[3];
+      dst4.s_addr = dst6_p->s6_addr[12];
       send_icmp_v4 (scanner->icmpv4soc, dst4_p);
     }
 }
@@ -431,7 +437,7 @@
     }
   else
     {
-      dst4.s_addr = dst6_p->s6_addr32[3];
+      dst4.s_addr = dst6_p->s6_addr[12];
       send_tcp_v4 (scanner, dst4_p);
     }
 }
@@ -445,7 +451,7 @@
 static void
 send_arp_v4 (int soc, struct in_addr *dst_p)
 {
-  struct sockaddr_ll soca;
+  struct sockaddr_dl soca;
   struct arp_hdr arphdr;
   int frame_length;
   uint8_t *ether_frame;
@@ -505,10 +511,10 @@
     }
 
   /* Fill in sockaddr_ll.*/
-  soca.sll_ifindex = ifaceindex;
-  soca.sll_family = AF_PACKET;
-  memcpy (soca.sll_addr, src_mac, 6 * sizeof (uint8_t));
-  soca.sll_halen = 6;
+  soca.sdl_index = ifaceindex;
+  soca.sdl_family = AF_LINK;
+  memcpy (soca.sdl_data, src_mac, 6 * sizeof (uint8_t));
+  soca.sdl_alen = 6;
 
   /* Fill ARP header.*/
   /* IP addresses. */
@@ -520,7 +526,7 @@
    * Protocol address length is length of IPv4.
    * OpCode is ARP request. */
   arphdr.htype = htons (1);
-  arphdr.ptype = htons (ETH_P_IP);
+  arphdr.ptype = htons(AF_INET);
   arphdr.hlen = 6;
   arphdr.plen = 4;
   arphdr.opcode = htons (1);
@@ -535,8 +541,8 @@
   memcpy (ether_frame, dst_mac, 6 * sizeof (uint8_t));
   memcpy (ether_frame + 6, src_mac, 6 * sizeof (uint8_t));
   /* ethernet type code */
-  ether_frame[12] = ETH_P_ARP / 256;
-  ether_frame[13] = ETH_P_ARP % 256;
+  ether_frame[12] = AF_ARP / 256;
+  ether_frame[13] = AF_ARP % 256;
   /* ARP header.  ETH_HDRLEN = 14, ARP_HDRLEN = 28 */
   memcpy (ether_frame + 14, &arphdr, 28 * sizeof (uint8_t));
 
@@ -592,7 +598,7 @@
     }
   else
     {
-      dst4.s_addr = dst6_p->s6_addr32[3];
+      dst4.s_addr = dst6_p->s6_addr[12];
       send_arp_v4 (scanner->arpv4soc, dst4_p);
     }
 }
