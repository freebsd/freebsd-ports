- includes workaround for https://github.com/ElmerCSC/elmerfem/issues/304

--- ElmerGUI/Application/cad/cadview.cpp.orig	2021-11-10 14:49:01 UTC
+++ ElmerGUI/Application/cad/cadview.cpp
@@ -74,7 +74,7 @@
 #include <BRepAdaptor_Curve2d.hxx>
 #include <BRepBndLib.hxx>
 #include <BRepGProp.hxx>
-#include <BRepMesh.hxx>
+#include <BRepMesh_IncrementalMesh.hxx>
 #include <BRepTools.hxx>
 #include <BRep_Builder.hxx>
 #include <BRep_Tool.hxx>
@@ -343,9 +343,6 @@ bool CadView::readFile(QString fileName) {
 
     const gp_Trsf &Transformation = Location.Transformation();
 
-    const Poly_Array1OfTriangle &Triangles = Triangulation->Triangles();
-    const TColgp_Array1OfPnt &Nodes = Triangulation->Nodes();
-
     int nofTriangles = Triangulation->NbTriangles();
     int nofNodes = Triangulation->NbNodes();
 
@@ -366,8 +363,8 @@ bool CadView::readFile(QString fileName) {
     vtkTriangle *triangle = vtkTriangle::New();
     partGrid->Allocate(nofTriangles, nofTriangles);
 
-    for (int i = Triangles.Lower(); i <= Triangles.Upper(); i++) {
-      Triangles(i).Get(n0, n1, n2);
+    for (int i = 1; i <= nofTriangles; i++) {
+      Triangulation->Triangle(i).Get(n0, n1, n2);
 
       if (Face.Orientation() != TopAbs_FORWARD) {
         int tmp = n2;
@@ -375,9 +372,9 @@ bool CadView::readFile(QString fileName) {
         n1 = tmp;
       }
 
-      triangle->GetPointIds()->SetId(0, n0 - Nodes.Lower());
-      triangle->GetPointIds()->SetId(1, n1 - Nodes.Lower());
-      triangle->GetPointIds()->SetId(2, n2 - Nodes.Lower());
+      triangle->GetPointIds()->SetId(0, n0 - 1);
+      triangle->GetPointIds()->SetId(1, n1 - 1);
+      triangle->GetPointIds()->SetId(2, n2 - 1);
 
       partGrid->InsertNextCell(triangle->GetCellType(),
                                triangle->GetPointIds());
@@ -385,13 +382,13 @@ bool CadView::readFile(QString fileName) {
 
     double x[3];
     vtkPoints *partPoints = vtkPoints::New();
-    for (int i = Nodes.Lower(); i <= Nodes.Upper(); i++) {
-      gp_XYZ XYZ = Nodes(i).Coord();
+    for (int i = 1; i <= nofNodes; i++) {
+      gp_XYZ XYZ = Triangulation->Node(i).Coord();
       Transformation.Transforms(XYZ);
       x[0] = XYZ.X();
       x[1] = XYZ.Y();
       x[2] = XYZ.Z();
-      partPoints->InsertPoint(i - Nodes.Lower(), x);
+      partPoints->InsertPoint(i - 1, x);
     }
 
     partGrid->SetPoints(partPoints);
