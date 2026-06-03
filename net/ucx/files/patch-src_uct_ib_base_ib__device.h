--- src/uct/ib/base/ib_device.h.orig	2026-02-05 12:41:56 UTC
+++ src/uct/ib/base/ib_device.h
@@ -20,8 +20,13 @@
 #include <ucs/sys/sock.h>
 
 #include <endian.h>
-#include <linux/ip.h>
-
+#if defined(__linux__)
+#  include <linux/ip.h>
+#  include <linux/ipv6.h>
+#else
+#  include <netinet/ip.h>
+#  include <netinet/ip6.h>
+#endif
 
 #define UCT_IB_QPN_ORDER                  24  /* How many bits can be an IB QP number */
 #define UCT_IB_UIDX_SHIFT                 8   /* BE uidx shift */
