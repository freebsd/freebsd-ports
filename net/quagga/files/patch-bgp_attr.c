--- bgpd/bgp_attr.c.orig	2008-10-02 16:28:50.000000000 +0800
+++ bgpd/bgp_attr.c	2009-04-30 16:33:56.000000000 +0800
@@ -857,7 +857,7 @@
 	  && ! aspath_firstas_check (attr->aspath, peer->as))
  	{
  	  zlog (peer->log, LOG_ERR,
- 		"%s incorrect first AS (must be %d)", peer->host, peer->as);
+ 		"%s incorrect first AS (must be %u)", peer->host, peer->as);
  	  bgp_notify_send (peer,
  			   BGP_NOTIFY_UPDATE_ERR,
  			   BGP_NOTIFY_UPDATE_MAL_AS_PATH);
