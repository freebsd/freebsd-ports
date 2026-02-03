- includes workaround for https://github.com/ElmerCSC/elmerfem/issues/304

--- ElmerGUI/Application/cad/cadview.cpp.orig	2020-11-10 19:52:44 UTC
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
@@ -104,7 +104,7 @@ static void pickEventHandler(vtkObject* caller, unsign
   QVTKWidget* qvtkWidget = cadView->GetQVTKWidget();
 #endif
 
-  vtkAbstractPicker* picker = qvtkWidget->GetInteractor()->GetPicker();
+  vtkAbstractPicker* picker = qvtkWidget->interactor()->GetPicker();
   vtkPropPicker* propPicker = vtkPropPicker::SafeDownCast(picker);
   vtkActor* actor = propPicker->GetActor();
 
@@ -146,15 +146,15 @@ CadView::CadView(QWidget *parent) : QMainWindow(parent
 
   renderer = vtkRenderer::New();
   renderer->SetBackground(1, 1, 1);
-  qVTKWidget->GetRenderWindow()->AddRenderer(renderer);
+  qVTKWidget->renderWindow()->AddRenderer(renderer);
   renderer->GetRenderWindow()->Render();
 
   vtkPropPicker *propPicker = vtkPropPicker::New();
   vtkCallbackCommand *cbcPick = vtkCallbackCommand::New();
-  qVTKWidget->GetInteractor()->SetPicker(propPicker);
+  qVTKWidget->interactor()->SetPicker(propPicker);
   cbcPick->SetClientData(this);
   cbcPick->SetCallback(pickEventHandler);
-  qVTKWidget->GetInteractor()->GetPicker()->AddObserver(vtkCommand::PickEvent,
+  qVTKWidget->interactor()->GetPicker()->AddObserver(vtkCommand::PickEvent,
                                                         cbcPick);
   propPicker->Delete();
   cbcPick->Delete();
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
@@ -490,7 +487,7 @@ bool CadView::readFile(QString fileName) {
   // Draw:
   //------
   renderer->ResetCamera();  
-  qVTKWidget->GetRenderWindow()->Render();
+  qVTKWidget->renderWindow()->Render();
 
   QCoreApplication::processEvents();
 
