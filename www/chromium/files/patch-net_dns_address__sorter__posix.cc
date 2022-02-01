--- net/dns/address_sorter_posix.cc.orig	2021-12-14 11:45:09 UTC
+++ net/dns/address_sorter_posix.cc
@@ -15,7 +15,9 @@
 #include <sys/socket.h>  // Must be included before ifaddrs.h.
 #include <ifaddrs.h>
 #include <net/if.h>
+#include <net/if_var.h>
 #include <netinet/in_var.h>
+#include <netinet6/in6_var.h>
 #include <string.h>
 #include <sys/ioctl.h>
 #endif
