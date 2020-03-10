--- ElmerGUI/Application/cad/cadview.cpp.orig	2020-03-06 10:30:22 UTC
+++ ElmerGUI/Application/cad/cadview.cpp
@@ -69,7 +69,7 @@
 #include <TopoDS_Shape.hxx>
 #include <BRepTools.hxx>
 #include <TopTools_HSequenceOfShape.hxx>
-#include <BRepMesh.hxx>
+#include <BRepMesh_IncrementalMesh.hxx>
 #include <TopExp_Explorer.hxx>
 #include <TopoDS_Face.hxx>
 #include <TopoDS.hxx>
