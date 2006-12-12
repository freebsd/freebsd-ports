--- bgpd/bgpd.c.orig	Fri Dec  8 05:24:44 2006
+++ bgpd/bgpd.c	Tue Dec 12 15:34:44 2006
@@ -60,6 +60,9 @@
 #ifdef HAVE_SNMP
 #include "bgpd/bgp_snmp.h"
 #endif /* HAVE_SNMP */
+#ifndef TCP_SIG_SPI_BASE
+#define TCP_SIG_SPI_BASE 1000 /* XXX this will go away */
+#endif
 
 /* BGP process wide configuration.  */
 static struct bgp_master bgp_master;
@@ -788,6 +791,7 @@
   peer->status = Idle;
   peer->ostatus = Idle;
   peer->weight = 0;
+  peer->password[0] = '\0';
   peer->bgp = bgp;
   peer = peer_lock (peer); /* initial reference */
 
@@ -3379,6 +3383,55 @@
   return 0;
 }
 
+#ifdef QUAGGA_TCP_MD5SIG
+/* Set password for authenticating with the peer. */
+int
+peer_password_set (struct peer *peer, char *password)
+{
+  struct bgp *bgp = peer->bgp;
+  int len;
+
+  len = strlen(password);
+
+  if ((len < PEER_PASSWORD_MINLEN) || (len > PEER_PASSWORD_MAXLEN))
+    return BGP_ERR_INVALID_VALUE;
+
+  memcpy(peer->password, password, len);
+
+  /*
+   * XXX Need to do PF_KEY operation here to add an SA entry,
+   * and add an SP entry for this peer's packet flows also.
+   */
+
+  SET_FLAG (peer->flags, PEER_FLAG_TCP_SIGNATURE);
+
+  if (peer->fd >= 0)
+    sockopt_tcp_signature (peer->su.sa.sa_family, peer->fd, TCP_SIG_SPI_BASE +
+      peer->port);
+
+  return 0;
+}
+
+int
+peer_password_unset (struct peer *peer)
+{
+  struct bgp *bgp = peer->bgp;
+
+  UNSET_FLAG (peer->flags, PEER_FLAG_TCP_SIGNATURE);
+  /* Paranoia. */
+  memset(peer->password, 0, sizeof(peer->password));
+
+  if (peer->fd >= 0)
+    sockopt_tcp_signature (peer->su.sa.sa_family, peer->fd, 0);
+
+  /*
+   * XXX Need to do PF_KEY operation here to remove the SA and SP.
+   */
+
+  return 0;
+}
+#endif /* QUAGGA_TCP_MD5SIG */
+
 /* Set distribute list to the peer. */
 int
 peer_distribute_set (struct peer *peer, afi_t afi, safi_t safi, int direct, 
@@ -4409,6 +4462,13 @@
       if (peer->desc)
 	vty_out (vty, " neighbor %s description %s%s", addr, peer->desc,
 		 VTY_NEWLINE);
+
+#ifdef QUAGGA_TCP_MD5SIG
+      /* tcp-md5 session password. XXX the password should be obfuscated */
+      if (CHECK_FLAG (peer->flags, PEER_FLAG_TCP_SIGNATURE))
+	vty_out (vty, " neighbor %s password %s%s", addr, peer->password,
+		 VTY_NEWLINE);
+#endif /* QUAGGA_TCP_MD5SIG */
 
       /* Shutdown. */
       if (CHECK_FLAG (peer->flags, PEER_FLAG_SHUTDOWN))
