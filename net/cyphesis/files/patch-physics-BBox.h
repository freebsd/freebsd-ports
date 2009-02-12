--- physics/BBox.h.orig	2009-02-12 06:55:03.000000000 +0100
+++ physics/BBox.h	2009-02-12 19:24:05.000000000 +0100
@@ -20,7 +20,9 @@
 #ifndef PHYSICS_BBOX_H
 #define PHYSICS_BBOX_H
 
+#include <cmath>
 #include <wfmath/axisbox.h>
+#include <wfmath/point.h>
 
 typedef WFMath::AxisBox<3> BBox;
 
