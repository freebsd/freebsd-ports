--- arpscan.c.orig	Mon Aug 18 16:54:25 2003
+++ arpscan.c	Mon Mar 22 23:05:40 2004
@@ -17,6 +17,13 @@
 
 #define PCAP_TIMEO 20
 
+#ifdef __FreeBSD__
+# include <sys/param.h>
+# if __FreeBSD_version > 500000
+#  define NTOHL(x) (x) = ntohl((u_int32_t)(x))
+# endif
+#endif
+
 struct	ether_arp {
 	struct	 arp_hdr ea_hdr;
 	u_int8_t arp_sha[ETH_ADDR_LEN];
