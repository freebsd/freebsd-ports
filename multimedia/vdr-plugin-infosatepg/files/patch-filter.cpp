--- a/filter.cpp
+++ b/filter.cpp
@@ -6,6 +6,9 @@
  * $Id$
  */
 
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 #include <netinet/if_ether.h>
 #include <unistd.h>
 
@@ -47,24 +50,32 @@ u_short cFilterInfosatepg::foldsum(u_lon
     return ((u_short) ~sum);
 }
 
-u_short cFilterInfosatepg::IPChecksum(iphdr *ipHeader)
+u_short cFilterInfosatepg::IPChecksum(ip *ipHeader)
 {
-    return foldsum(do_sum(0, (u_char*) ipHeader, sizeof(iphdr)));
+    return foldsum(do_sum(0, (u_char*) ipHeader, sizeof(ip)));
 
 }   /* IpChecksum() */
 
 
-u_short cFilterInfosatepg::UDPChecksum(iphdr *ipHeader, udphdr *udpHeader)
+u_short cFilterInfosatepg::UDPChecksum(ip *ipHeader, udphdr *udpHeader)
 {
     u_long sum = 0;
 
     // Ip-Pseudo-Header
-    sum = do_sum(sum, (u_char*)(&ipHeader->saddr), sizeof(ipHeader->saddr));
-    sum = do_sum(sum, (u_char*)(&ipHeader->daddr), sizeof(ipHeader->daddr));
+    sum = do_sum(sum, (u_char*)(&ipHeader->ip_src), sizeof(ipHeader->ip_src));
+    sum = do_sum(sum, (u_char*)(&ipHeader->ip_dst), sizeof(ipHeader->ip_dst));
+#ifdef __linux__
     sum += udpHeader->len;
-    sum += ipHeader->protocol<<8;
+#else
+    sum += udpHeader->uh_ulen;
+#endif
+    sum += ipHeader->ip_p<<8;
 
+#ifdef __linux__
     sum = do_sum(sum, (u_char*)udpHeader, ntohs(udpHeader->len));
+#else
+    sum = do_sum(sum, (u_char*)udpHeader, ntohs(udpHeader->uh_ulen));
+#endif
 
     return foldsum(sum);
 }
@@ -78,27 +89,27 @@ void cFilterInfosatepg::Process(u_short 
 
     if (Data[0]!=0x3E) return;
 
-    struct ethhdr eth_hdr;
-    memset(&eth_hdr,0,sizeof(struct ethhdr));
+    struct ether_header eth_hdr;
+    memset(&eth_hdr,0,sizeof(struct ether_header));
 
-    eth_hdr.h_dest[0]=Data[11];
-    eth_hdr.h_dest[1]=Data[10];
-    eth_hdr.h_dest[2]=Data[9];
-    eth_hdr.h_dest[3]=Data[8];
-    eth_hdr.h_dest[4]=Data[4];
-    eth_hdr.h_dest[5]=Data[3];
+    eth_hdr.ether_dhost[0]=Data[11];
+    eth_hdr.ether_dhost[1]=Data[10];
+    eth_hdr.ether_dhost[2]=Data[9];
+    eth_hdr.ether_dhost[3]=Data[8];
+    eth_hdr.ether_dhost[4]=Data[4];
+    eth_hdr.ether_dhost[5]=Data[3];
 
     // check mac and range
     if (!global->CheckMAC(&eth_hdr)) return;
 
-    int mac = eth_hdr.h_dest[5];
+    int mac = eth_hdr.ether_dhost[5];
     global->ActualMac=mac;
 
-    struct iphdr *ip_hdr = (iphdr *) &Data[SECT_IP_HDR_START];
+    struct ip *ip_hdr = (ip *) &Data[SECT_IP_HDR_START];
     struct udphdr *udp_hdr = (udphdr *) &Data[SECT_UDP_HDR_START];
 
     // Only IPv4
-    if (ip_hdr->version!=4) return;
+    if (ip_hdr->ip_v!=4) return;
 
     // Check IP checksum
     if (IPChecksum(ip_hdr)!=0)
@@ -108,7 +119,7 @@ void cFilterInfosatepg::Process(u_short 
     }
 
     // Only UDP
-    if (ip_hdr->protocol!=17) return;
+    if (ip_hdr->ip_p!=17) return;
 
     // Check UDP checksum
     if (UDPChecksum(ip_hdr,udp_hdr)!=0)
@@ -149,8 +160,8 @@ void cFilterInfosatepg::Process(u_short 
 
 
 #ifdef VDRDEBUG
-    dsyslog("infosatepg: mac=%02x-%02x-%02x-%02x-%02x-%02x",eth_hdr.h_dest[0],eth_hdr.h_dest[1],
-            eth_hdr.h_dest[2],eth_hdr.h_dest[3],eth_hdr.h_dest[4],eth_hdr.h_dest[5] );
+    dsyslog("infosatepg: mac=%02x-%02x-%02x-%02x-%02x-%02x",eth_hdr.ether_dhost[0],eth_hdr.ether_dhost[1],
+            eth_hdr.ether_dhost[2],eth_hdr.ether_dhost[3],eth_hdr.ether_dhost[4],eth_hdr.ether_dhost[5] );
 
     dsyslog("infosatepg: tid=%04i tbl=%04i stbl=%04i day=%02i month=%02i pktnr=%03i pktcnt=%03i len=%i",
             ntohs(ishdr->technisatId),ishdr->tableId,ishdr->tablesubId,ishdr->day,
