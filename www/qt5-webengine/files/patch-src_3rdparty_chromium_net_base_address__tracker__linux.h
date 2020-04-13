--- src/3rdparty/chromium/net/base/address_tracker_linux.h.orig	2019-11-27 21:12:25 UTC
+++ src/3rdparty/chromium/net/base/address_tracker_linux.h
@@ -7,9 +7,6 @@
 
 #include <sys/socket.h>  // Needed to include netlink.
 // Mask superfluous definition of |struct net|. This is fixed in Linux 2.6.38.
-#define net net_kernel
-#include <linux/rtnetlink.h>
-#undef net
 #include <stddef.h>
 
 #include <map>
