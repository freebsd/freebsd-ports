--- src/3rdparty/chromium/net/dns/address_sorter_posix.cc.orig	2017-01-26 00:49:16 UTC
+++ src/3rdparty/chromium/net/dns/address_sorter_posix.cc
@@ -13,6 +13,7 @@
 #include <sys/socket.h>  // Must be included before ifaddrs.h.
 #include <ifaddrs.h>
 #include <net/if.h>
+#include <net/if_var.h>
 #include <netinet/in_var.h>
 #include <string.h>
 #include <sys/ioctl.h>
