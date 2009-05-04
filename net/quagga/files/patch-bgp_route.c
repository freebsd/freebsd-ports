--- bgpd/bgp_route.c.orig	2008-10-02 16:28:50.000000000 +0800
+++ bgpd/bgp_route.c	2009-04-30 16:33:56.000000000 +0800
@@ -834,7 +834,7 @@
     {
       if (BGP_DEBUG (filter, FILTER))  
         zlog (peer->log, LOG_DEBUG, 
-	      "%s [Update:SEND] suppress announcement to peer AS %d is AS path.",
+	      "%s [Update:SEND] suppress announcement to peer AS %u is AS path.",
 	      peer->host, peer->as);
       return 0;
     }
@@ -847,7 +847,7 @@
 	{
 	  if (BGP_DEBUG (filter, FILTER))  
 	    zlog (peer->log, LOG_DEBUG, 
-		  "%s [Update:SEND] suppress announcement to peer AS %d is AS path.",
+		  "%s [Update:SEND] suppress announcement to peer AS %u is AS path.",
 		  peer->host,
 		  bgp->confed_id);
 	  return 0;
@@ -1163,7 +1163,7 @@
     {
       if (BGP_DEBUG (filter, FILTER))
         zlog (rsclient->log, LOG_DEBUG,
-             "%s [Update:SEND] suppress announcement to peer AS %d is AS path.",
+             "%s [Update:SEND] suppress announcement to peer AS %u is AS path.",
              rsclient->host, rsclient->as);
       return 0;
     }
@@ -5956,7 +5956,7 @@
       if (CHECK_FLAG (binfo->flags, BGP_INFO_STALE))
 	vty_out (vty, ", (stale)");
       if (CHECK_FLAG (attr->flag, ATTR_FLAG_BIT (BGP_ATTR_AGGREGATOR)))
-	vty_out (vty, ", (aggregated by %d %s)", 
+	vty_out (vty, ", (aggregated by %u %s)", 
 	         attr->extra->aggregator_as,
 		 inet_ntoa (attr->extra->aggregator_addr));
       if (CHECK_FLAG (binfo->peer->af_flags[afi][safi], PEER_FLAG_REFLECTOR_CLIENT))
