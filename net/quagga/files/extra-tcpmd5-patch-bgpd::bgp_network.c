--- bgpd/bgp_network.c.orig	Wed Aug 27 05:09:14 2003
+++ bgpd/bgp_network.c	Wed Jan  7 14:24:34 2004
@@ -35,6 +35,10 @@
 #include "bgpd/bgp_debug.h"
 #include "bgpd/bgp_network.h"
 
+#ifndef TCP_SIG_SPI_BASE
+#define TCP_SIG_SPI_BASE 1000 /* XXX this will go away */
+#endif
+
 extern struct zebra_privs_t bgpd_privs;
 
 
@@ -141,6 +145,15 @@
       return ret;
     }
 #endif /* SO_BINDTODEVICE */
+
+#ifdef TCP_MD5SIG
+  if (CHECK_FLAG (peer->flags, PEER_FLAG_TCP_SIGNATURE))
+    sockopt_tcp_signature (peer->su.sa.sa_family, peer->fd,
+      TCP_SIG_SPI_BASE + peer->port);
+  else
+    sockopt_tcp_signature (peer->su.sa.sa_family, peer->fd, 0);
+#endif /* TCP_MD5SIG */
+
   return 0;
 }
 
@@ -243,6 +256,12 @@
   if (peer->ifname)
     ifindex = if_nametoindex (peer->ifname);
 #endif /* HAVE_IPV6 */
+
+#ifdef TCP_MD5SIG
+  if (CHECK_FLAG (peer->flags, PEER_FLAG_TCP_SIGNATURE))
+    sockopt_tcp_signature (peer->su.sa.sa_family, peer->fd,
+      TCP_SIG_SPI_BASE + peer->port);
+#endif /* TCP_MD5SIG */
 
   if (BGP_DEBUG (events, EVENTS))
     plog_info (peer->log, "%s [Event] Connect start to %s fd %d",
