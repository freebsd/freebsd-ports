--- src/uct/ib/base/ib_device.c.orig	2026-03-02 11:31:24 UTC
+++ src/uct/ib/base/ib_device.c
@@ -30,6 +30,14 @@
 #include <rdma/rdma_netlink.h>
 #endif
 
+#ifndef s6_addr32
+#  if defined(__FreeBSD__)
+#    define s6_addr32 __u6_addr.__u6_addr32
+#  elif defined(__linux__)
+#    define s6_addr32 u6_addr.u6_addr32
+#  endif
+#endif
+
 #define UCT_IB_DEVICE_LOOPBACK_NDEV_INDEX_INVALID 0
 
 
