--- ./net/dns/address_sorter_posix.cc.orig	2014-08-12 21:02:40.000000000 +0200
+++ ./net/dns/address_sorter_posix.cc	2014-08-13 09:56:57.000000000 +0200
@@ -10,6 +10,7 @@
 #include <sys/socket.h>  // Must be included before ifaddrs.h.
 #include <ifaddrs.h>
 #include <net/if.h>
+#include <net/if_var.h>
 #include <netinet/in_var.h>
 #include <string.h>
 #include <sys/ioctl.h>
