--- src/rx/rx_kernel.h.orig	2014-09-24 10:17:09.000000000 -0400
+++ src/rx/rx_kernel.h	2014-09-28 20:37:20.000000000 -0400
@@ -54,12 +54,20 @@
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
