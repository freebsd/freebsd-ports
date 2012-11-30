--- cnupm/aggr_port.c.orig	2012-11-30 15:29:58.000000000 +0100
+++ cnupm/aggr_port.c	2012-11-30 15:30:30.000000000 +0100
@@ -120,7 +120,6 @@
 {
 	struct aggr_port_entry *ap;
 
-	port = port;
 	RB_FOREACH(ap, aggr_port_tree, &aggr_port_tree)
 		if (port >= ap->ape_first && port <= ap->ape_last)
 			return (ap->ape_port != 0 ? ap->ape_port : port);
