--- xsysstats.c.orig	2000-05-30 06:39:48 UTC
+++ xsysstats.c
@@ -1,5 +1,4 @@
 #include "xsysstats.h"
-#include "headers.h"
 #include "patchlevel.h"
 
 struct base_types {
@@ -48,6 +47,7 @@ struct base_types types[NUM_TYPES] = {
 {"icpu", "icpu", 100}, 
 };
 
+struct graph_info *graphs;
 
 /* Various notes:
  * we store the values in the 'points' variable.  They are stored in the
