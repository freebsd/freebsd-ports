--- tools/icmp6.c.orig	2013-08-27 18:35:24.000000000 +0900
+++ tools/icmp6.c	2013-10-03 17:02:09.000000000 +0900
@@ -47,6 +47,7 @@
 #include <netinet/ip6.h>
 #include <netinet/icmp6.h>
 #include <pwd.h>
+#include <sys/socket.h>
 #include <net/if.h>
 #include <ifaddrs.h>
 #ifdef __linux__
@@ -54,7 +55,6 @@
 #elif defined (__FreeBSD__) || defined(__NetBSD__) || defined (__OpenBSD__) || defined(__APPLE__)
 	#include <net/if_dl.h>
 #endif
-#include <sys/socket.h>
 #include "icmp6.h"
 #include "ipv6toolkit.h"
 #include <netinet/tcp.h>
