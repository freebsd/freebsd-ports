--- src/rx/rx_kernel.h.orig	2017-12-05 14:52:48 UTC
+++ src/rx/rx_kernel.h
@@ -58,12 +58,20 @@ extern int osi_utoa(char *buf, size_t len, unsigned lo
 #endif
 #define rx_ifnet_mtu(x) (x)->if_mtu
 #define rx_ifnet_flags(x) (x?(x)->if_flags:0)
-#if defined(AFS_OBSD46_ENV) || defined(AFS_FBSD81_ENV)
+#if __FreeBSD_version >= 1100032
+#define rx_ifaddr_withnet(x) ifa_ifwithnet(x, 0, RT_ALL_FIBS)
+#elif defined(AFS_OBSD46_ENV) || defined(AFS_FBSD81_ENV)
 #define rx_ifaddr_withnet(x) ifa_ifwithnet(x, 0)
 #else
 #define rx_ifaddr_withnet(x) ifa_ifwithnet(x)
 #endif
+#if defined(AFS_FBSD81_ENV)
+#if defined(if_metric)
 #define rx_ifnet_metric(x) (x?(x)->if_data.ifi_metric:0)
+#else
+#define rx_ifnet_metric(x) (x?(x)->if_metric:0)
+#endif
+#endif
 #define rx_ifaddr_ifnet(x) (x?(x)->ifa_ifp:0)
 #define rx_ifaddr_address_family(x) (x)->ifa_addr->sa_family
 #define rx_ifaddr_address(x, y, z) memcpy(y, (x)->ifa_addr, z)
