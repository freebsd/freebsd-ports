--- src/3rdparty/chromium/net/dns/address_sorter_posix.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/net/dns/address_sorter_posix.cc
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
