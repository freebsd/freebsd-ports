--- ElmerGUI/Application/cad/cadview.cpp.orig	2020-06-26 12:18:06 UTC
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
