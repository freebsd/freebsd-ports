--- applications/utilities/postProcessing/graphics/PVFoamReader/vtkFoam/vtkFoam.C.orig	Tue Aug  9 16:34:44 2005
+++ applications/utilities/postProcessing/graphics/PVFoamReader/vtkFoam/vtkFoam.C	Sat Dec 24 18:06:03 2005
@@ -36,12 +36,12 @@
 #include "volPointInterpolation.H"
 
 #include "vtkFoamReader.h"
-#include "vtkDataArraySelection.h"
-#include "vtkUnstructuredGrid.h"
-#include "vtkPointData.h"
-#include "vtkCellData.h"
-#include "vtkFloatArray.h"
-#include "vtkCharArray.h"
+#include <vtk/vtkDataArraySelection.h>
+#include <vtk/vtkUnstructuredGrid.h>
+#include <vtk/vtkPointData.h>
+#include <vtk/vtkCellData.h>
+#include <vtk/vtkFloatArray.h>
+#include <vtk/vtkCharArray.h>
 
 // * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //
 
