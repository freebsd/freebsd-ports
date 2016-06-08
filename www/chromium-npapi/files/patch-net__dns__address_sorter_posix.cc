--- ./net/dns/address_sorter_posix.cc.orig	2014-04-30 22:43:08.000000000 +0200
+++ ./net/dns/address_sorter_posix.cc	2014-05-04 14:38:48.000000000 +0200
@@ -10,6 +10,7 @@
 #include <sys/socket.h>  // Must be included before ifaddrs.h.
 #include <ifaddrs.h>
 #include <net/if.h>
+#include <net/if_var.h>
 #include <netinet/in_var.h>
 #include <string.h>
 #include <sys/ioctl.h>
