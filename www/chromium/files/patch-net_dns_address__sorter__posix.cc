--- net/dns/address_sorter_posix.cc.orig	2017-07-25 21:04:58.000000000 +0200
+++ net/dns/address_sorter_posix.cc	2017-08-02 21:07:01.353407000 +0200
@@ -13,7 +13,9 @@
 #include <sys/socket.h>  // Must be included before ifaddrs.h.
 #include <ifaddrs.h>
 #include <net/if.h>
+#include <net/if_var.h>
 #include <netinet/in_var.h>
+#include <netinet6/in6_var.h>
 #include <string.h>
 #include <sys/ioctl.h>
 #endif
