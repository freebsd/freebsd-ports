--- trace.c.orig	Fri Sep 29 11:55:16 2006
+++ trace.c	Fri Sep 29 11:55:35 2006
@@ -133,7 +133,7 @@
     /* determine the routing table entry for this traceroute */
     mrt = find_route(qry->tr_src, group, MRTF_SG | MRTF_WC | MRTF_PMBR,
 		     DONT_CREATE);
-    IF_DEBUG(DEBUG_TRACE)
+    IF_DEBUG(DEBUG_TRACE) {
 	if (mrt != (mrtentry_t *)NULL) {
 	    if (mrt->upstream != (pim_nbr_entry_t *)NULL)
 		parent_address = mrt->upstream->address;
@@ -147,7 +147,7 @@
 		*/
 	} else
 	    log(LOG_DEBUG, 0, "...no route");
-    
+    }
     /*
      * Query type packet - check if rte exists 
      * Check if the query destination is a vif connected to me.
