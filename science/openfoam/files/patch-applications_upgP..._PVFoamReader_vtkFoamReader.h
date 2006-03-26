--- applications/utilities/postProcessing/graphics/PVFoamReader/PVFoamReader/vtkFoamReader.h.orig	Mon Jul  4 12:34:01 2005
+++ applications/utilities/postProcessing/graphics/PVFoamReader/PVFoamReader/vtkFoamReader.h	Sat Dec 24 17:59:14 2005
@@ -37,7 +37,7 @@
 
 // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
 
-#include "vtkDataSetSource.h"
+#include <vtk/vtkDataSetSource.h>
 #include "vtkFoamData.h"
 
 // * * * * * * * * * * * * * Forward Declarations  * * * * * * * * * * * * * //
