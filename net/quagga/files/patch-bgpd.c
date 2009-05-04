--- bgpd/bgpd.c.orig	2008-09-11 13:46:49.000000000 +0800
+++ bgpd/bgpd.c	2009-04-30 16:33:56.000000000 +0800
@@ -4512,13 +4512,13 @@
 	    vty_out (vty, " neighbor %s peer-group%s", addr,
 		     VTY_NEWLINE);
 	  if (peer->as)
-	    vty_out (vty, " neighbor %s remote-as %d%s", addr, peer->as,
+	    vty_out (vty, " neighbor %s remote-as %u%s", addr, peer->as,
 		     VTY_NEWLINE);
 	}
       else
 	{
 	  if (! g_peer->as)
-	    vty_out (vty, " neighbor %s remote-as %d%s", addr, peer->as,
+	    vty_out (vty, " neighbor %s remote-as %u%s", addr, peer->as,
 		     VTY_NEWLINE);
 	  if (peer->af_group[AFI_IP][SAFI_UNICAST])
 	    vty_out (vty, " neighbor %s peer-group %s%s", addr,
@@ -4528,7 +4528,7 @@
       /* local-as. */
       if (peer->change_local_as)
 	if (! peer_group_active (peer))
-	  vty_out (vty, " neighbor %s local-as %d%s%s", addr,
+	  vty_out (vty, " neighbor %s local-as %u%s%s", addr,
 		   peer->change_local_as,
 		   CHECK_FLAG (peer->flags, PEER_FLAG_LOCAL_AS_NO_PREPEND) ?
 		   " no-prepend" : "", VTY_NEWLINE);
@@ -4917,7 +4917,7 @@
 	vty_out (vty, "!%s", VTY_NEWLINE);
 
       /* Router bgp ASN */
-      vty_out (vty, "router bgp %d", bgp->as);
+      vty_out (vty, "router bgp %u", bgp->as);
 
       if (bgp_option_check (BGP_OPT_MULTIPLE_INSTANCE))
 	{
@@ -4978,7 +4978,7 @@
 	  vty_out (vty, " bgp confederation peers");
 
          for (i = 0; i < bgp->confed_peers_cnt; i++)
-           vty_out(vty, " %d", bgp->confed_peers[i]);
+           vty_out(vty, " %u", bgp->confed_peers[i]);
 
           vty_out (vty, "%s", VTY_NEWLINE);
 	}
