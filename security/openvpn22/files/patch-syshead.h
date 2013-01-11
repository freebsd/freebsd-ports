Work around "missing" TCP_NODELAY,
obtained from: http://community.openvpn.net/openvpn/ticket/158

--- ./syshead.h.orig	2012-11-22 13:07:51.000000000 +0100
+++ ./syshead.h	2013-01-11 21:30:07.000000000 +0100
@@ -298,6 +298,10 @@
 #include <netinet/ip.h>
 #endif
 
+#ifdef HAVE_NETINET_TCP_H
+#include <netinet/tcp.h>
+#endif
+
 #ifdef HAVE_NET_IF_TUN_H
 #include <net/if_tun.h>
 #endif
