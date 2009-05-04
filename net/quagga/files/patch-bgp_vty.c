--- bgpd/bgp_vty.c.orig	2008-09-11 13:46:49.000000000 +0800
+++ bgpd/bgp_vty.c	2009-04-30 16:33:56.000000000 +0800
@@ -334,11 +334,11 @@
 	       VTY_NEWLINE);
       return CMD_WARNING;
     case BGP_ERR_AS_MISMATCH:
-      vty_out (vty, "BGP is already running; AS is %d%s", as, VTY_NEWLINE);
+      vty_out (vty, "BGP is already running; AS is %u%s", as, VTY_NEWLINE);
       return CMD_WARNING;
     case BGP_ERR_INSTANCE_MISMATCH:
       vty_out (vty, "BGP view name and AS number mismatch%s", VTY_NEWLINE);
-      vty_out (vty, "BGP instance is already running; AS is %d%s",
+      vty_out (vty, "BGP instance is already running; AS is %u%s",
 	       as, VTY_NEWLINE);
       return CMD_WARNING;
     }
@@ -1280,10 +1280,10 @@
   switch (ret)
     {
     case BGP_ERR_PEER_GROUP_MEMBER:
-      vty_out (vty, "%% Peer-group AS %d. Cannot configure remote-as for member%s", as, VTY_NEWLINE);
+      vty_out (vty, "%% Peer-group AS %u. Cannot configure remote-as for member%s", as, VTY_NEWLINE);
       return CMD_WARNING;
     case BGP_ERR_PEER_GROUP_PEER_TYPE_DIFFERENT:
-      vty_out (vty, "%% The AS# can not be changed from %d to %s, peer-group members must be all internal or all external%s", as, as_str, VTY_NEWLINE);
+      vty_out (vty, "%% The AS# can not be changed from %u to %s, peer-group members must be all internal or all external%s", as, as_str, VTY_NEWLINE);
       return CMD_WARNING;
     }
   return bgp_vty_return (vty, ret);
@@ -1601,7 +1601,7 @@
 
   if (ret == BGP_ERR_PEER_GROUP_PEER_TYPE_DIFFERENT)
     {
-      vty_out (vty, "%% Peer with AS %d cannot be in this peer-group, members must be all internal or all external%s", as, VTY_NEWLINE);
+      vty_out (vty, "%% Peer with AS %u cannot be in this peer-group, members must be all internal or all external%s", as, VTY_NEWLINE);
       return CMD_WARNING;
     }
 
@@ -6669,7 +6669,7 @@
               
               /* Usage summary and header */
               vty_out (vty,
-                       "BGP router identifier %s, local AS number %d%s",
+                       "BGP router identifier %s, local AS number %u%s",
                        inet_ntoa (bgp->router_id), bgp->as, VTY_NEWLINE);
 
               ents = bgp_table_count (bgp->rib[afi][safi]);
@@ -6716,7 +6716,7 @@
 
 	  vty_out (vty, "4 ");
 
-	  vty_out (vty, "%5d %7d %7d %8d %4d %4lu ",
+	  vty_out (vty, "%5u %7d %7d %8d %4d %4lu ",
 		   peer->as,
 		   peer->open_in + peer->update_in + peer->keepalive_in
 		   + peer->notify_in + peer->refresh_in + peer->dynamic_cap_in,
@@ -7226,8 +7226,8 @@
 
   /* Configured IP address. */
   vty_out (vty, "BGP neighbor is %s, ", p->host);
-  vty_out (vty, "remote AS %d, ", p->as);
-  vty_out (vty, "local AS %d%s, ",
+  vty_out (vty, "remote AS %u, ", p->as);
+  vty_out (vty, "local AS %u%s, ",
 	   p->change_local_as ? p->change_local_as : p->local_as,
 	   CHECK_FLAG (p->flags, PEER_FLAG_LOCAL_AS_NO_PREPEND) ?
 	   " no-prepend" : "");
@@ -8009,7 +8009,7 @@
                       "Route Server's BGP router identifier %s%s",
                       inet_ntoa (bgp->router_id), VTY_NEWLINE);
              vty_out (vty,
-              "Route Server's local AS number %d%s", bgp->as,
+              "Route Server's local AS number %u%s", bgp->as,
                        VTY_NEWLINE);
 
              vty_out (vty, "%s", VTY_NEWLINE);
