--- dump_mesh_vtm.cpp.orig	2022-10-23 21:34:40 UTC
+++ dump_mesh_vtm.cpp
@@ -60,6 +60,8 @@
 #include <vtkMPI.h>
 #include <vtkMPICommunicator.h>
 
+#include <vtkVersionMacros.h>
+
 using namespace LAMMPS_NS;
 
 /* ---------------------------------------------------------------------- */
