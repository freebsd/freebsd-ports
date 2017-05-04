--- net/dns/address_sorter_posix.cc.orig	2017-04-19 19:06:36 UTC
+++ net/dns/address_sorter_posix.cc
@@ -13,6 +13,7 @@
 #include <sys/socket.h>  // Must be included before ifaddrs.h.
 #include <ifaddrs.h>
 #include <net/if.h>
+#include <net/if_var.h>
 #include <netinet/in_var.h>
 #include <string.h>
 #include <sys/ioctl.h>
