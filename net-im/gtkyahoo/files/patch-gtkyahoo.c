--- gtkyahoo.c.orig	2007-11-12 15:21:19.000000000 +0100
+++ gtkyahoo.c	2007-11-12 15:21:22.000000000 +0100
@@ -1456,6 +1456,7 @@
 	int setgeom = 0;
 	int curarg = 1;
 	GtkAllocation initial_geometry;
+	initial_geometry.x = initial_geometry.y = initial_geometry.width = initial_geometry.height = 0;
 
 	DBG_Open(NULL);
 
