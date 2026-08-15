--- VTK/IO/OCCT/vtkOCCTReader.cxx.orig	2026-05-22 16:18:17 UTC
+++ VTK/IO/OCCT/vtkOCCTReader.cxx
@@ -26,8 +26,6 @@
 #include <Poly_Triangulation.hxx>
 #include <Quantity_Color.hxx>
 #include <STEPCAFControl_Reader.hxx>
-#include <Standard_PrimitiveTypes.hxx>
-#include <TColgp_Array1OfVec.hxx>
 #include <TDF_ChildIterator.hxx>
 #include <TDataStd_Name.hxx>
 #include <TDocStd_Document.hxx>
@@ -92,7 +90,7 @@ class vtkOCCTReader::vtkInternals (public)
     vtkNew<vtkCellArray> trianglesCells;
     vtkNew<vtkCellArray> linesCells;
 
-    Standard_Integer shift = 0;
+    int shift = 0;
 
     if (this->Parent->GetReadWire())
     {
@@ -109,7 +107,7 @@ class vtkOCCTReader::vtkInternals (public)
           // meshing
           BRepMesh_IncrementalMesh(edge, this->Parent->GetLinearDeflection(),
             this->Parent->GetRelativeDeflection(), this->Parent->GetAngularDeflection(),
-            Standard_True);
+            true);
         }
 
         if (poly.IsNull())
@@ -117,11 +115,11 @@ class vtkOCCTReader::vtkInternals (public)
           continue;
         }
 
-        Standard_Integer nbV = poly->NbNodes();
+        int nbV = poly->NbNodes();
 
         // Points
-        const TColgp_Array1OfPnt& aNodes = poly->Nodes();
-        for (Standard_Integer i = 1; i <= nbV; i++)
+        const NCollection_Array1<gp_Pnt>& aNodes = poly->Nodes();
+        for (int i = 1; i <= nbV; i++)
         {
           gp_Pnt pt = aNodes(i).Transformed(location);
           points->InsertNextPoint(pt.X(), pt.Y(), pt.Z());
@@ -163,7 +161,7 @@ class vtkOCCTReader::vtkInternals (public)
         // meshing
         BRepMesh_IncrementalMesh(face, this->Parent->GetLinearDeflection(),
           this->Parent->GetRelativeDeflection(), this->Parent->GetAngularDeflection(),
-          Standard_True);
+          true);
       }
 
       if (poly.IsNull())
@@ -174,11 +172,11 @@ class vtkOCCTReader::vtkInternals (public)
       Poly::ComputeNormals(poly);
       TopAbs_Orientation faceOrientation = face.Orientation();
 
-      Standard_Integer nbT = poly->NbTriangles();
-      Standard_Integer nbV = poly->NbNodes();
+      int nbT = poly->NbTriangles();
+      int nbV = poly->NbNodes();
 
       // Points
-      for (Standard_Integer i = 1; i <= nbV; i++)
+      for (int i = 1; i <= nbV; i++)
       {
         gp_Pnt pt = poly->Node(i).Transformed(location);
         points->InsertNextPoint(pt.X(), pt.Y(), pt.Z());
@@ -187,7 +185,7 @@ class vtkOCCTReader::vtkInternals (public)
       // Normals
       if (poly->HasNormals())
       {
-        for (Standard_Integer i = 1; i <= nbV; i++)
+        for (int i = 1; i <= nbV; i++)
         {
           gp_Dir n = poly->Normal(i);
           float fn[3] = { static_cast<float>(n.X()), static_cast<float>(n.Y()),
@@ -203,7 +201,7 @@ class vtkOCCTReader::vtkInternals (public)
       {
         // just in case a face does not have normals, add a dummy normal
         float fn[3] = { 0.0, 0.0, 1.0 };
-        for (Standard_Integer i = 1; i <= nbV; i++)
+        for (int i = 1; i <= nbV; i++)
         {
           normals->InsertNextTypedTuple(fn);
         }
@@ -212,7 +210,7 @@ class vtkOCCTReader::vtkInternals (public)
       // UVs
       if (poly->HasUVNodes())
       {
-        for (Standard_Integer i = 1; i <= nbV; i++)
+        for (int i = 1; i <= nbV; i++)
         {
           gp_Pnt2d uv = poly->UVNode(i);
           float fn[2] = { static_cast<float>(uv.X()), static_cast<float>(uv.Y()) };
@@ -222,7 +220,7 @@ class vtkOCCTReader::vtkInternals (public)
       else
       {
         float fn[3] = { 0.0, 0.0 };
-        for (Standard_Integer i = 1; i <= nbV; i++)
+        for (int i = 1; i <= nbV; i++)
         {
           uvs->InsertNextTypedTuple(fn);
         }
@@ -424,7 +422,7 @@ class ProgressIndicator : public Message_ProgressIndic
   ProgressIndicator(vtkOCCTReader* reader) { this->Reader = reader; }
 
 protected:
-  void Show(const Message_ProgressScope&, const Standard_Boolean) override
+  void Show(const Message_ProgressScope&, const bool) override
   {
     double currentPosition = this->GetPosition();
     if (currentPosition - this->LastPosition > 0.01)
@@ -489,12 +487,12 @@ int vtkOCCTReader::RequestData(
   this->Internals->ShapeTool = XCAFDoc_DocumentTool::ShapeTool(doc->Main());
   this->Internals->ColorTool = XCAFDoc_DocumentTool::ColorTool(doc->Main());
 
-  TDF_LabelSequence topLevelShapes;
+  NCollection_Sequence<TDF_Label> topLevelShapes;
 
   // create polydata leaves
   this->Internals->ShapeTool->GetShapes(topLevelShapes);
 
-  for (Standard_Integer iLabel = 1; iLabel <= topLevelShapes.Length(); ++iLabel)
+  for (int iLabel = 1; iLabel <= topLevelShapes.Length(); ++iLabel)
   {
     TDF_Label label = topLevelShapes.Value(iLabel);
 
@@ -513,7 +511,7 @@ int vtkOCCTReader::RequestData(
 
   vtkNew<vtkMatrix4x4> mat;
   mat->Identity();
-  for (Standard_Integer iLabel = 1; iLabel <= topLevelShapes.Length(); ++iLabel)
+  for (int iLabel = 1; iLabel <= topLevelShapes.Length(); ++iLabel)
   {
     this->Internals->AddLabel(topLevelShapes.Value(iLabel), mat, output);
   }
