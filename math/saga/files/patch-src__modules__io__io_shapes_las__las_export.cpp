--- src/modules/io/io_shapes_las/las_export.cpp.orig	2014-01-09 10:24:11 UTC
+++ src/modules/io/io_shapes_las/las_export.cpp
@@ -333,12 +333,12 @@ bool CLAS_Export::On_Execute(void)
 		y	= pPoints->Get_Y(i);
 		z	= pPoints->Get_Z(i);
 
-		x < xmin ? xmin = x : NULL;
-		x > xmax ? xmax = x : NULL;
-		y < ymin ? ymin = y : NULL;
-		y > ymax ? ymax = y : NULL;
-		z < zmin ? zmin = z : NULL;
-		z > zmax ? zmax = z : NULL;
+		x < xmin ? xmin = x : 0.0;
+		x > xmax ? xmax = x : 0.0;
+		y < ymin ? ymin = y : 0.0;
+		y > ymax ? ymax = y : 0.0;
+		z < zmin ? zmin = z : 0.0;
+		z > zmax ? zmax = z : 0.0;
 
 		point.SetCoordinates(x, y, z);
 
