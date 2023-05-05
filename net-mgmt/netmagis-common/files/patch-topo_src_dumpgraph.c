--- topo/src/dumpgraph.c.orig	2023-04-26 07:46:02 UTC
+++ topo/src/dumpgraph.c
@@ -3,8 +3,6 @@
 
 #include "graph.h"
 
-MOBJ *mobjlist [NB_MOBJ] ;
-
 void usage (char *progname)
 {
     fprintf (stderr, "Usage : %s [-a|-n cidr|-v vlan|-e regexp|-E regexp|-t|-m]* [-o obj]\n", progname) ;
