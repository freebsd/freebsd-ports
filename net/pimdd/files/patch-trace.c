--- trace.c.orig	1999-11-30 17:58:53 UTC
+++ trace.c
@@ -133,7 +133,7 @@ accept_mtrace(src, dst, group, data, no,
     /* determine the routing table entry for this traceroute */
     mrt = find_route(qry->tr_src, group, MRTF_SG | MRTF_WC | MRTF_PMBR,
 		     DONT_CREATE);
-    IF_DEBUG(DEBUG_TRACE)
+    IF_DEBUG(DEBUG_TRACE) {
 	if (mrt != (mrtentry_t *)NULL) {
 	    if (mrt->upstream != (pim_nbr_entry_t *)NULL)
 		parent_address = mrt->upstream->address;
@@ -147,7 +147,7 @@ accept_mtrace(src, dst, group, data, no,
 		*/
 	} else
 	    log(LOG_DEBUG, 0, "...no route");
-    
+    }
     /*
      * Query type packet - check if rte exists 
      * Check if the query destination is a vif connected to me.
