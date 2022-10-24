--- dump_vtk.cpp.orig	2022-10-23 21:34:06 UTC
+++ dump_vtk.cpp
@@ -59,6 +59,8 @@
 #include <vtkXMLPImageDataWriter.h>
 #include <sstream>
 
+#include <vtkVersionMacros.h>
+
 namespace LAMMPS_NS
 {
 
