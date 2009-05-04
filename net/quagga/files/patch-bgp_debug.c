--- bgpd/bgp_debug.c.orig	2008-09-05 22:27:26.000000000 +0800
+++ bgpd/bgp_debug.c	2009-04-30 16:33:56.000000000 +0800
@@ -205,7 +205,7 @@
     snprintf (buf + strlen (buf), size - strlen (buf), ", atomic-aggregate");
 
   if (CHECK_FLAG (attr->flag, ATTR_FLAG_BIT (BGP_ATTR_AGGREGATOR)))
-    snprintf (buf + strlen (buf), size - strlen (buf), ", aggregated by %d %s",
+    snprintf (buf + strlen (buf), size - strlen (buf), ", aggregated by %u %s",
 	      attr->extra->aggregator_as,
 	      inet_ntoa (attr->extra->aggregator_addr));
