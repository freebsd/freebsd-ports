--- roverpingd/receive.c.orig	Sun Aug  1 15:55:04 2004
+++ roverpingd/receive.c	Sun Aug  1 15:55:43 2004
@@ -170,9 +170,7 @@
 #ifdef __DEBUG_DATA_POINTS__
       /* assumes NUM_DATA_POINTS == 20... can't use loop here because */
       /* because it will get interrupted causing disjointed output... */
-      if ( debuggin) { fprintf(stderr,"node %d data...
-  %d %d %d %d %d %d %d %d %d %d
-  %d %d %d %d %d %d %d %d %d %d (next=%d)\n", 
+      if ( debuggin) { fprintf(stderr,"node %d data...\n %d %d %d %d %d %d %d %d %d %d\n %d %d %d %d %d %d %d %d %d %d (next=%d)\n", 
         idx,
         ping_list[idx]->n_latency_data[0], ping_list[idx]->n_latency_data[1],
         ping_list[idx]->n_latency_data[2], ping_list[idx]->n_latency_data[3],
