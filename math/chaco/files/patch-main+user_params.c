--- main/user_params.c.orig	Sun Apr 27 14:04:34 1997
+++ main/user_params.c	Mon May  1 22:17:29 2006
@@ -98,7 +98,7 @@
 long      RANDOM_SEED = 7654321L;	/* Seed for random number generator */
 int       NSQRTS = 1000;	/* # square roots to precompute if coarsening */
 int       MAKE_VWGTS = FALSE;	/* Make vtx weights degrees+1? (TRUE/FALSE) */
-int       FREE_GRAPH = TRUE;	/* Free input graph data? (TRUE/FALSE) */
+int       FREE_GRAPH = FALSE;	/* Free input graph data? (TRUE/FALSE) */
 char     *PARAMS_FILENAME = "User_Params";	/* File of parameter changes */
 
 
