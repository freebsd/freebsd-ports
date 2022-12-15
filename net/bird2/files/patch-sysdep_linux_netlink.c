--- sysdep/linux/netlink.c.orig	2022-12-15 15:03:21 UTC
+++ sysdep/linux/netlink.c
@@ -27,15 +27,15 @@
 #include "lib/hash.h"
 #include "conf/conf.h"
 
+#ifdef CONFIG_FREEBSD_NETLINK
+#include <netlink/netlink.h>
+#include <netlink/netlink_route.h>
+#endif
 #ifdef CONFIG_LINUX_NETLINK
 #include <asm/types.h>
 #include <linux/if.h>
 #include <linux/netlink.h>
 #include <linux/rtnetlink.h>
-#endif
-#ifdef CONFIG_FREEBSD_NETLINK
-#include <netlink/netlink.h>
-#include <netlink/netlink_route.h>
 #endif
 
 #ifdef HAVE_MPLS_KERNEL
