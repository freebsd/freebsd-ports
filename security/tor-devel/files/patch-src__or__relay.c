--- src/or/relay.c.orig	2013-06-14 04:07:30.000000000 -0400
+++ src/or/relay.c	2013-06-15 05:20:19.000000000 -0400
@@ -2482,6 +2482,10 @@
     streams_blocked = circ->streams_blocked_on_p_chan;
   }
 
+  /*
+   * Disabling this for now because of a possible guard discovery attack
+   */
+#if 0
   /* Are we a middle circuit about to exceed ORCIRC_MAX_MIDDLE_CELLS? */
   if ((circ->n_chan != NULL) && CIRCUIT_IS_ORCIRC(circ)) {
     orcirc = TO_OR_CIRCUIT(circ);
@@ -2505,6 +2509,7 @@
       }
     }
   }
+#endif
 
   cell_queue_append_packed_copy(queue, cell, chan->wide_circ_ids);
 
