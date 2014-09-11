--- src/rx/rx_kernel.h.orig	2014-09-11 17:20:18.000000000 +0900
+++ src/rx/rx_kernel.h	2014-09-11 17:23:52.000000000 +0900
@@ -59,7 +59,13 @@
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
