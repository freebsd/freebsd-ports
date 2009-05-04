--- bgpd/bgp_packet.c.orig	2008-09-10 04:18:57.000000000 +0800
+++ bgpd/bgp_packet.c	2009-04-30 16:33:56.000000000 +0800
@@ -813,7 +813,7 @@
   length = bgp_packet_set_size (s);
 
   if (BGP_DEBUG (normal, NORMAL))
-    zlog_debug ("%s sending OPEN, version %d, my as %d, holdtime %d, id %s", 
+    zlog_debug ("%s sending OPEN, version %d, my as %u, holdtime %d, id %s", 
 	       peer->host, BGP_VERSION_4, local_as,
 	       send_holdtime, inet_ntoa (peer->local_id));
 
@@ -1184,7 +1184,7 @@
 
   /* Receive OPEN message log  */
   if (BGP_DEBUG (normal, NORMAL))
-    zlog_debug ("%s rcv OPEN, version %d, remote-as (in open) %d,"
+    zlog_debug ("%s rcv OPEN, version %d, remote-as (in open) %u,"
                 " holdtime %d, id %s",
 	        peer->host, version, remote_as, holdtime,
 	        inet_ntoa (remote_id));
@@ -1277,7 +1277,7 @@
 	  else
 	    {
 	      if (BGP_DEBUG (normal, NORMAL))
-		zlog_debug ("%s bad OPEN, remote AS is %d, expected %d",
+		zlog_debug ("%s bad OPEN, remote AS is %u, expected %u",
 			    peer->host, remote_as, peer->as);
 	      bgp_notify_send_with_data (peer, BGP_NOTIFY_OPEN_ERR,
 					 BGP_NOTIFY_OPEN_BAD_PEER_AS,
@@ -1430,7 +1430,7 @@
   if (remote_as != peer->as)
     {
       if (BGP_DEBUG (normal, NORMAL))
-	zlog_debug ("%s bad OPEN, remote AS is %d, expected %d",
+	zlog_debug ("%s bad OPEN, remote AS is %u, expected %u",
 		   peer->host, remote_as, peer->as);
       bgp_notify_send_with_data (peer, 
 				 BGP_NOTIFY_OPEN_ERR, 
