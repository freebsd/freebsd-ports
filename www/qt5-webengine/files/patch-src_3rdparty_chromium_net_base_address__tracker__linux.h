--- src/3rdparty/chromium/net/base/address_tracker_linux.h.orig	2016-11-07 14:46:18 UTC
+++ src/3rdparty/chromium/net/base/address_tracker_linux.h
@@ -6,10 +6,12 @@
 #define NET_BASE_ADDRESS_TRACKER_LINUX_H_
 
 #include <sys/socket.h>  // Needed to include netlink.
+#if !defined(__FreeBSD__)
 // Mask superfluous definition of |struct net|. This is fixed in Linux 2.6.38.
 #define net net_kernel
 #include <linux/rtnetlink.h>
 #undef net
+#endif
 #include <stddef.h>
 
 #include <map>
