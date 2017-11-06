--- src/layer2.c.orig	2014-09-14 19:16:31 UTC
+++ src/layer2.c
@@ -9,7 +9,14 @@
 
 #include <string.h>
 
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <netinet/in_systm.h>
+#include <netinet/in.h>
+#else
 #include <netinet/ether.h>
+#endif
+
 #include <netinet/ip.h>
 #include <netinet/ip6.h>
 
@@ -19,6 +26,18 @@
 #include "packetcapture.h"          /* for datalink_info_t */
 #include "layer2.h"
 
+#ifdef __FreeBSD__
+#define ETH_P_IP        0x0800
+#define ETH_P_IPV6      0x86DD
+#define ETH_ALEN        6
+#define ETH_P_ARP	0x0806
+struct ethhdr {
+	unsigned char   h_dest[ETH_ALEN];
+	unsigned char   h_source[ETH_ALEN];
+	u_int16_t       h_proto;
+} __attribute__((packed));
+#endif
+
 /* ETH_P_PAE is named ETHERTYPE_PAE in freebsd, define it  */
 #ifndef ETH_P_PAE
 #define ETH_P_PAE 0x888E
