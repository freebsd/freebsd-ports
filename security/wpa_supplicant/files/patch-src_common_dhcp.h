--- src/common/dhcp.h.orig	2024-07-20 18:04:37 UTC
+++ src/common/dhcp.h
@@ -9,6 +9,22 @@
 #ifndef DHCP_H
 #define DHCP_H
 
+/*
+ * Translate Linux to FreeBSD
+ */
+#define iphdr		ip
+#define ihl		ip_hl
+#define verson		ip_v
+#define tos		ip_tos
+#define tot_len		ip_len
+#define id		ip_id
+#define frag_off	ip_off
+#define ttl		ip_ttl
+#define protocol	ip_p
+#define check		ip_sum
+#define saddr		ip_src
+#define daddr		ip_dst
+
 #include <netinet/ip.h>
 #if __FAVOR_BSD
 #include <netinet/udp.h>
