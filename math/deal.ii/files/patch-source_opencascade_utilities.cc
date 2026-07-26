--- source/opencascade/utilities.cc.orig	2026-07-25 14:03:25 UTC
+++ source/opencascade/utilities.cc
@@ -465,7 +465,7 @@ namespace OpenCASCADE
   {
     TopoDS_Edge                           out_shape;
     const TopoDS_Shape                   &edges = in_shape;
-    std::vector<Handle_Geom_BoundedCurve> intersections;
+    std::vector<opencascade::handle<Geom_BoundedCurve>> intersections;
     TopLoc_Location                       L;
     Standard_Real                         First;
     Standard_Real                         Last;
