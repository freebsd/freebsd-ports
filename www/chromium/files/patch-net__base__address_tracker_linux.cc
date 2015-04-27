--- net/base/address_tracker_linux.cc.orig	2015-04-19 20:31:08.000000000 +0200
+++ net/base/address_tracker_linux.cc	2015-04-19 20:36:27.000000000 +0200
@@ -5,7 +5,9 @@
 #include "net/base/address_tracker_linux.h"
 
 #include <errno.h>
+#if !defined(OS_FREEBSD)
 #include <linux/if.h>
+#endif
 #include <sys/ioctl.h>
 
 #include "base/files/scoped_file.h"
@@ -24,6 +26,7 @@
 bool GetAddress(const struct nlmsghdr* header,
                 IPAddressNumber* out,
                 bool* really_deprecated) {
+#if !defined(OS_FREEBSD)
   if (really_deprecated)
     *really_deprecated = false;
   const struct ifaddrmsg* msg =
@@ -76,6 +79,9 @@
     return false;
   out->assign(address, address + address_length);
   return true;
+#else
+  return false;
+#endif
 }
 
 }  // namespace
@@ -128,6 +134,7 @@
 }
 
 void AddressTrackerLinux::Init() {
+#if !defined(OS_FREEBSD)
   netlink_fd_ = socket(AF_NETLINK, SOCK_RAW, NETLINK_ROUTE);
   if (netlink_fd_ < 0) {
     PLOG(ERROR) << "Could not create NETLINK socket";
@@ -215,6 +222,10 @@
       return;
     }
   }
+#else
+  AbortAndForceOnline();
+  return;
+#endif
 }
 
 void AddressTrackerLinux::AbortAndForceOnline() {
@@ -250,6 +261,7 @@
 void AddressTrackerLinux::ReadMessages(bool* address_changed,
                                        bool* link_changed,
                                        bool* tunnel_changed) {
+#if !defined(OS_FREEBSD)
   *address_changed = false;
   *link_changed = false;
   *tunnel_changed = false;
@@ -276,6 +288,7 @@
   }
   if (*link_changed || *address_changed)
     UpdateCurrentConnectionType();
+#endif
 }
 
 void AddressTrackerLinux::HandleMessage(char* buffer,
@@ -283,6 +296,7 @@
                                         bool* address_changed,
                                         bool* link_changed,
                                         bool* tunnel_changed) {
+#if !defined(OS_FREEBSD)
   DCHECK(buffer);
   for (struct nlmsghdr* header = reinterpret_cast<struct nlmsghdr*>(buffer);
        NLMSG_OK(header, length);
@@ -365,6 +379,7 @@
         break;
     }
   }
+#endif
 }
 
 void AddressTrackerLinux::OnFileCanReadWithoutBlocking(int fd) {
@@ -391,8 +406,12 @@
 
 bool AddressTrackerLinux::IsTunnelInterface(int interface_index) const {
   // Linux kernel drivers/net/tun.c uses "tun" name prefix.
+#if !defined(OS_FREEBSD)
   char buf[IFNAMSIZ] = {0};
   return strncmp(get_interface_name_(interface_index, buf), "tun", 3) == 0;
+#else
+  return false;
+#endif
 }
 
 void AddressTrackerLinux::UpdateCurrentConnectionType() {
