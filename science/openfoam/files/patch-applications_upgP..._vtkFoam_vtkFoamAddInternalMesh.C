--- applications/utilities/postProcessing/graphics/PVFoamReader/vtkFoam/vtkFoamAddInternalMesh.C.orig	Wed Jun 22 14:33:48 2005
+++ applications/utilities/postProcessing/graphics/PVFoamReader/vtkFoam/vtkFoamAddInternalMesh.C	Thu Jan  5 00:20:12 2006
@@ -30,8 +30,8 @@
 #include "fvMesh.H"
 #include "cellModeller.H"
 
-#include "vtkUnstructuredGrid.h"
-#include "vtkCellArray.h"
+#include <vtk/vtkUnstructuredGrid.h>
+#include <vtk/vtkCellArray.h>
 
 #include "vtkFoamInsertNextPoint.H"
 
