--- net/base/address_tracker_linux.h.orig	2015-04-15 00:18:56.000000000 +0200
+++ net/base/address_tracker_linux.h	2015-04-19 20:29:29.000000000 +0200
@@ -6,10 +6,12 @@
 #define NET_BASE_ADDRESS_TRACKER_LINUX_H_
 
 #include <sys/socket.h>  // Needed to include netlink.
+#if !defined(__FreeBSD__)
 // Mask superfluous definition of |struct net|. This is fixed in Linux 2.6.38.
 #define net net_kernel
 #include <linux/rtnetlink.h>
 #undef net
+#endif
 
 #include <map>
 
@@ -32,7 +34,11 @@
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
