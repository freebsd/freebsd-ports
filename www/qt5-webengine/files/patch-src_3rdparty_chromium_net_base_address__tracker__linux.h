--- src/3rdparty/chromium/net/base/address_tracker_linux.h.orig	2017-01-26 00:49:16 UTC
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
@@ -34,8 +36,11 @@ namespace internal {
 class NET_EXPORT_PRIVATE AddressTrackerLinux :
     public base::MessageLoopForIO::Watcher {
  public:
+#if !defined(__FreeBSD__)
   typedef std::map<IPAddress, struct ifaddrmsg> AddressMap;
-
+#else
+  typedef void* AddressMap;
+#endif
   // Non-tracking version constructor: it takes a snapshot of the
   // current system configuration. Once Init() returns, the
   // configuration is available through GetOnlineLinks() and
