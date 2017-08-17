Needed on FreeBSD 10.3.
--- src/3rdparty/chromium/net/dns/address_sorter_posix.cc.orig	2017-04-20 10:17:24 UTC
+++ src/3rdparty/chromium/net/dns/address_sorter_posix.cc
@@ -11,6 +11,7 @@
 #include <sys/socket.h>  // Must be included before ifaddrs.h.
 #include <ifaddrs.h>
 #include <net/if.h>
+#include <net/if_var.h>
 #include <netinet/in_var.h>
 #include <string.h>
 #include <sys/ioctl.h>
