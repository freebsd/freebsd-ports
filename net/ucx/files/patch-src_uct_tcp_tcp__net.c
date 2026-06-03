--- src/uct/tcp/tcp_net.c.orig	2026-02-04 09:52:46 UTC
+++ src/uct/tcp/tcp_net.c
@@ -12,10 +12,16 @@
 #include "tcp.h"
 
 #include <ucs/sys/string.h>
+
+#if defined(__linux__)
 #include <linux/sockios.h>
 #include <linux/types.h>
 #include <linux/ethtool.h>
 #include <linux/if_ether.h>
+#else
+#  include <net/ethernet.h>
+#endif
+
 #include <sys/ioctl.h>
 #include <net/if_arp.h>
 #include <net/if.h>
@@ -28,6 +34,7 @@ ucs_status_t uct_tcp_netif_caps(const char *if_name, d
 ucs_status_t uct_tcp_netif_caps(const char *if_name, double *latency_p,
                                 double *bandwidth_p)
 {
+    #if defined(__linux__)
     struct ethtool_cmd edata;
     uint32_t speed_mbps;
     ucs_status_t status;
@@ -104,10 +111,37 @@ ucs_status_t uct_tcp_netif_caps(const char *if_name, d
     *bandwidth_p = (speed_mbps * 1e6) / 8 *
                    (mtu - 40) / (mtu + ll_headers); /* TCP/IP header is 40 bytes */
     return UCS_OK;
+#else
+    ucs_status_t status;
+    struct ifreq ifr;
+    uint32_t speed_mbps = 1000; /* best-effort default */
+    size_t mtu          = 1500; /* fallback */
+    size_t ll_headers;
+
+    memset(&ifr, 0, sizeof(ifr));
+
+    status = ucs_netif_ioctl(if_name, SIOCGIFMTU, &ifr);
+    if (status == UCS_OK) {
+        mtu = (size_t)ifr.ifr_mtu;
+    }
+
+    /*
+     * Ethernet framing estimate:
+     * preamble(7) + SFD(1) + ethernet header + CRC + IFG(12)
+     */
+    ll_headers = 7 + 1 + ETHER_HDR_LEN + ETHER_CRC_LEN + 12;
+
+    /* Same model as Linux path */
+    *latency_p   = 576.0 / (speed_mbps * 1e6) + 5.2e-6;
+    *bandwidth_p = (speed_mbps * 1e6) / 8 *
+                   (mtu - 40) / (mtu + ll_headers);
+    return UCS_OK;
+#endif
 }
 
 ucs_status_t uct_tcp_netif_is_default(const char *if_name, int *result_p)
 {
+#if defined(__linux__)
     static const char *filename = "/proc/net/route";
     in_addr_t netmask;
     char name[128];
@@ -139,4 +173,9 @@ out:
 out:
     fclose(f);
     return UCS_OK;
+#else
+    (void)if_name;
+    *result_p = 0;
+    return UCS_OK;
+#endif
 }
