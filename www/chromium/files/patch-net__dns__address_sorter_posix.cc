--- net/dns/address_sorter_posix.cc.orig	2014-10-10 08:54:16 UTC
+++ net/dns/address_sorter_posix.cc
@@ -10,6 +10,7 @@
 #include <sys/socket.h>  // Must be included before ifaddrs.h.
 #include <ifaddrs.h>
 #include <net/if.h>
+#include <net/if_var.h>
 #include <netinet/in_var.h>
 #include <string.h>
 #include <sys/ioctl.h>
