--- applications/utilities/postProcessing/graphics/PVFoamReader/vtkFoam/vtkFoamAddPatch.C.orig	Wed Jun 22 14:33:48 2005
+++ applications/utilities/postProcessing/graphics/PVFoamReader/vtkFoam/vtkFoamAddPatch.C	Fri Jan  6 12:29:38 2006
@@ -29,8 +29,8 @@
 #include "vtkFoam.H"
 #include "polyPatch.H"
 
-#include "vtkUnstructuredGrid.h"
-#include "vtkCellArray.h"
+#include <vtk/vtkUnstructuredGrid.h>
+#include <vtk/vtkCellArray.h>
 
 #include "vtkFoamInsertNextPoint.H"
 
