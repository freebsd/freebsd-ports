--- src/layer2.c.orig	2013-05-12 15:16:43 UTC
+++ src/layer2.c
@@ -3,7 +3,10 @@
 #include <string.h>
 #include <assert.h>
 
-#include <netinet/ether.h>
+//#include <netinet/ether.h>
+#include <sys/types.h>
+#include <netinet/in_systm.h>
+#include <netinet/in.h>
 #include <netinet/ip.h>
 #include <netinet/ip6.h>
 
@@ -12,6 +15,15 @@
 #include "log.h"
 #include "layer2.h"
 
+#define ETH_P_IP        0x0800
+#define ETH_P_IPV6      0x86DD
+#define ETH_ALEN        6
+struct ethhdr {
+        unsigned char   h_dest[ETH_ALEN];
+        unsigned char   h_source[ETH_ALEN];
+        u_int16_t       h_proto;
+} __attribute__((packed));
+
 int handle_link_layer(datalink_info_t *info, const u_char *pkt, uint8_t *nextproto,
 			int *offsetnext)
 {
