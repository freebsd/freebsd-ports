--- net/base/address_tracker_linux.h.orig	2016-03-04 23:14:54.569478409 +0100
+++ net/base/address_tracker_linux.h	2016-03-04 23:15:49.769474661 +0100
@@ -6,10 +6,12 @@
 #define NET_BASE_ADDRESS_TRACKER_LINUX_H_
 
 #include <sys/socket.h>  // Needed to include netlink.
+#if !defined(OS_FREEBSD)
 // Mask superfluous definition of |struct net|. This is fixed in Linux 2.6.38.
 #define net net_kernel
 #include <linux/rtnetlink.h>
 #undef net
+#endif
 #include <stddef.h>
 
 #include <map>
@@ -33,7 +35,11 @@
 class NET_EXPORT_PRIVATE AddressTrackerLinux :
     public base::MessageLoopForIO::Watcher {
  public:
+#if !defined(OS_FREEBSD)
   typedef std::map<IPAddressNumber, struct ifaddrmsg> AddressMap;
+#else
+  typedef void* AddressMap;
+#endif
 
   // Non-tracking version constructor: it takes a snapshot of the
   // current system configuration. Once Init() returns, the
