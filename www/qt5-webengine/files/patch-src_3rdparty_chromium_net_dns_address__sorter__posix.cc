--- src/3rdparty/chromium/net/dns/address_sorter_posix.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/net/dns/address_sorter_posix.cc
@@ -14,6 +14,7 @@
 #include <ifaddrs.h>
 #include <net/if.h>
 #include <netinet/in_var.h>
+#include <netinet6/in6_var.h>
 #include <string.h>
 #include <sys/ioctl.h>
 #endif
