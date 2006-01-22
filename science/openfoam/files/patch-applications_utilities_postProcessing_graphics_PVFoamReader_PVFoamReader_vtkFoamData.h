--- ./applications/utilities/postProcessing/graphics/PVFoamReader/PVFoamReader/vtkFoamData.h.orig	Wed Jun 22 14:33:47 2005
+++ ./applications/utilities/postProcessing/graphics/PVFoamReader/PVFoamReader/vtkFoamData.h	Tue Jan  3 18:43:11 2006
@@ -37,7 +37,7 @@
 
 // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
 
-#include "vtkDataSetSource.h"
+#include <vtk/vtkDataSetSource.h>
 
 /*---------------------------------------------------------------------------*\
                          Class vtkFoamData Declaration
