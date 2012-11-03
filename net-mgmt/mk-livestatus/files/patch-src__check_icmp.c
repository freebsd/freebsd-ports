--- ./src/check_icmp.c.orig	2012-11-03 13:00:18.000000000 +0100
+++ ./src/check_icmp.c	2012-11-03 13:05:33.000000000 +0100
@@ -65,12 +65,19 @@
 #include <netdb.h>
 #include <sys/socket.h>
 #include <net/if.h>
+#ifdef __FreeBSD__
+#include <netinet/in.h>
+#include <arpa/inet.h>
+#include <netinet/ip.h>
+#endif
 #include "/usr/include/netinet/ip_icmp.h"
 // #include <netinet/ip_icmp.h>
 #include <netinet/in_systm.h>
+#ifndef __FreeBSD__
 #include <netinet/in.h>
 #include <netinet/ip.h>
 #include <arpa/inet.h>
+#endif
 #include <signal.h>
 #include <float.h>
 
