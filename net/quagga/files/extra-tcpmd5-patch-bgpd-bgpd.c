--- bgpd/bgpd.c.orig	2008-09-11 09:46:49.000000000 +0400
+++ bgpd/bgpd.c	2008-12-15 19:48:53.000000000 +0300
@@ -60,6 +60,9 @@
 #ifdef HAVE_SNMP
 #include "bgpd/bgp_snmp.h"
 #endif /* HAVE_SNMP */
+#ifndef TCP_SIG_SPI_BASE
+#define TCP_SIG_SPI_BASE 1000 /* XXX this will go away */
+#endif
 
 /* BGP process wide configuration.  */
 static struct bgp_master bgp_master;
@@ -3402,110 +3405,55 @@
   return 0;
 }
 
+
+#ifdef QUAGGA_TCP_MD5SIG
 /* Set password for authenticating with the peer. */
 int
 peer_password_set (struct peer *peer, const char *password)
 {
-  struct listnode *nn, *nnode;
-  int len = password ? strlen(password) : 0;
-  int ret = BGP_SUCCESS;
+  struct bgp *bgp = peer->bgp;
+  int len;
+
+  len = strlen(password);
 
   if ((len < PEER_PASSWORD_MINLEN) || (len > PEER_PASSWORD_MAXLEN))
     return BGP_ERR_INVALID_VALUE;
 
-  if (peer->password && strcmp (peer->password, password) == 0
-      && ! CHECK_FLAG (peer->sflags, PEER_STATUS_GROUP))
-    return 0;
+  memcpy(peer->password, password, len);
 
-  if (peer->password)
-    XFREE (MTYPE_PEER_PASSWORD, peer->password);
-  
-  peer->password = XSTRDUP (MTYPE_PEER_PASSWORD, password);
-
-  if (! CHECK_FLAG (peer->sflags, PEER_STATUS_GROUP))
-    {
-      if (peer->status == Established)
-          bgp_notify_send (peer, BGP_NOTIFY_CEASE, BGP_NOTIFY_CEASE_CONFIG_CHANGE);
-      else
-        BGP_EVENT_ADD (peer, BGP_Stop);
-        
-      return (bgp_md5_set (peer) >= 0) ? BGP_SUCCESS : BGP_ERR_TCPSIG_FAILED;
-    }
+  /*
+   * XXX Need to do PF_KEY operation here to add an SA entry,
+   * and add an SP entry for this peer's packet flows also.
+   */
 
-  for (ALL_LIST_ELEMENTS (peer->group->peer, nn, nnode, peer))
-    {
-      if (peer->password && strcmp (peer->password, password) == 0)
-	continue;
-      
-      if (peer->password)
-        XFREE (MTYPE_PEER_PASSWORD, peer->password);
-      
-      peer->password = XSTRDUP(MTYPE_PEER_PASSWORD, password);
+  SET_FLAG (peer->flags, PEER_FLAG_TCP_SIGNATURE);
 
-      if (peer->status == Established)
-        bgp_notify_send (peer, BGP_NOTIFY_CEASE, BGP_NOTIFY_CEASE_CONFIG_CHANGE);
-      else
-        BGP_EVENT_ADD (peer, BGP_Stop);
-      
-      if (bgp_md5_set (peer) < 0)
-        ret = BGP_ERR_TCPSIG_FAILED;
-    }
+  if (peer->fd >= 0)
+    sockopt_tcp_signature (peer->su.sa.sa_family, peer->fd, TCP_SIG_SPI_BASE +
+      peer->port);
 
-  return ret;
+  return 0;
 }
 
 int
 peer_password_unset (struct peer *peer)
 {
-  struct listnode *nn, *nnode;
-
-  if (!peer->password
-      && !CHECK_FLAG (peer->sflags, PEER_STATUS_GROUP))
-    return 0;
-
-  if (!CHECK_FLAG (peer->sflags, PEER_STATUS_GROUP))
-    {
-      if (peer_group_active (peer)
-	  && peer->group->conf->password
-	  && strcmp (peer->group->conf->password, peer->password) == 0)
-	return BGP_ERR_PEER_GROUP_HAS_THE_FLAG;
-
-      if (peer->status == Established)
-        bgp_notify_send (peer, BGP_NOTIFY_CEASE, BGP_NOTIFY_CEASE_CONFIG_CHANGE);
-      else
-        BGP_EVENT_ADD (peer, BGP_Stop);
-
-      if (peer->password)
-        XFREE (MTYPE_PEER_PASSWORD, peer->password);
-      
-      peer->password = NULL;
-      
-      bgp_md5_set (peer);
-
-      return 0;
-    }
-
-  XFREE (MTYPE_PEER_PASSWORD, peer->password);
-  peer->password = NULL;
+  struct bgp *bgp = peer->bgp;
 
-  for (ALL_LIST_ELEMENTS (peer->group->peer, nn, nnode, peer))
-    {
-      if (!peer->password)
-	continue;
+  UNSET_FLAG (peer->flags, PEER_FLAG_TCP_SIGNATURE);
+  /* Paranoia. */
+  memset(peer->password, 0, sizeof(peer->password));
 
-      if (peer->status == Established)
-        bgp_notify_send (peer, BGP_NOTIFY_CEASE, BGP_NOTIFY_CEASE_CONFIG_CHANGE);
-      else
-        BGP_EVENT_ADD (peer, BGP_Stop);
-      
-      XFREE (MTYPE_PEER_PASSWORD, peer->password);
-      peer->password = NULL;
+  if (peer->fd >= 0)
+    sockopt_tcp_signature (peer->su.sa.sa_family, peer->fd, 0);
 
-      bgp_md5_set (peer);
-    }
+  /*
+   * XXX Need to do PF_KEY operation here to remove the SA and SP.
+   */
 
   return 0;
 }
+#endif /* QUAGGA_TCP_MD5SIG */
 
 /* Set distribute list to the peer. */
 int
@@ -4538,6 +4486,13 @@
 	vty_out (vty, " neighbor %s description %s%s", addr, peer->desc,
 		 VTY_NEWLINE);
 
+#ifdef QUAGGA_TCP_MD5SIG
+      /* tcp-md5 session password. XXX the password should be obfuscated */
+      if (CHECK_FLAG (peer->flags, PEER_FLAG_TCP_SIGNATURE))
+	vty_out (vty, " neighbor %s password %s%s", addr, peer->password,
+		 VTY_NEWLINE);
+#endif /* QUAGGA_TCP_MD5SIG */
+
       /* Shutdown. */
       if (CHECK_FLAG (peer->flags, PEER_FLAG_SHUTDOWN))
         if (! peer_group_active (peer) ||
