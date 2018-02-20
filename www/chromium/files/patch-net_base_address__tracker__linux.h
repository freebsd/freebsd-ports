--- net/base/address_tracker_linux.h.orig	2018-01-04 21:05:55.000000000 +0100
+++ net/base/address_tracker_linux.h	2018-01-21 13:43:10.477307000 +0100
@@ -7,9 +7,6 @@
 
 #include <sys/socket.h>  // Needed to include netlink.
 // Mask superfluous definition of |struct net|. This is fixed in Linux 2.6.38.
-#define net net_kernel
-#include <linux/rtnetlink.h>
-#undef net
 #include <stddef.h>
 
 #include <map>
