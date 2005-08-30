--- bgpd/bgp_network.c.orig	Wed Dec  8 12:41:23 2004
+++ bgpd/bgp_network.c	Fri Jan 28 17:52:57 2005
@@ -35,6 +35,10 @@
 #include "bgpd/bgp_debug.h"
 #include "bgpd/bgp_network.h"
 
+#ifndef TCP_SIG_SPI_BASE
+#define TCP_SIG_SPI_BASE 1000 /* XXX this will go away */
+#endif
+
 extern struct zebra_privs_t bgpd_privs;
 
 
@@ -148,6 +152,15 @@
       return ret;
     }
 #endif /* SO_BINDTODEVICE */
+
+#ifdef QUAGGA_TCP_MD5SIG
+  if (CHECK_FLAG (peer->flags, PEER_FLAG_TCP_SIGNATURE))
+    sockopt_tcp_signature (peer->su.sa.sa_family, peer->fd,
+      TCP_SIG_SPI_BASE + peer->port);
+  else
+    sockopt_tcp_signature (peer->su.sa.sa_family, peer->fd, 0);
+#endif /* QUAGGA_TCP_MD5SIG */
+
   return 0;
 }
 
@@ -250,6 +263,12 @@
   if (peer->ifname)
     ifindex = if_nametoindex (peer->ifname);
 #endif /* HAVE_IPV6 */
+
+#ifdef QUAGGA_TCP_MD5SIG
+  if (CHECK_FLAG (peer->flags, PEER_FLAG_TCP_SIGNATURE))
+    sockopt_tcp_signature (peer->su.sa.sa_family, peer->fd,
+      TCP_SIG_SPI_BASE + peer->port);
+#endif /* QUAGGA_TCP_MD5SIG */
 
   if (BGP_DEBUG (events, EVENTS))
     plog_debug (peer->log, "%s [Event] Connect start to %s fd %d",
