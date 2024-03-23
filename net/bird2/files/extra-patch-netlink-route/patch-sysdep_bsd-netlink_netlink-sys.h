--- sysdep/bsd-netlink/netlink-sys.h.orig	2024-03-22 14:19:18 UTC
+++ sysdep/bsd-netlink/netlink-sys.h
@@ -9,6 +9,7 @@
 #ifndef _BIRD_NETLINK_SYS_H_
 #define _BIRD_NETLINK_SYS_H_
 
+#include "netlink-route.h"
 #include <netlink/netlink.h>
 #include <netlink/netlink_route.h>
 
