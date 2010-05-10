--- src/dx.c.orig	2010-04-11 19:29:06.000000000 +0200
+++ src/dx.c	2010-04-11 19:32:05.000000000 +0200
@@ -19,12 +19,14 @@
 
 #include <string.h>
 #include <math.h>
-#include <dx/dx.h>
 
 #include "simulation.h"
 #include "init.h"
 #include "solid.h"
 
+/* workaround glib 2.24. gvariant.h error */
+#include <dx/dx.h>
+
 static void ftt_cell_neighbors_not_periodic (FttCell * cell,
 					     FttCellNeighbors * neighbor)
 {
