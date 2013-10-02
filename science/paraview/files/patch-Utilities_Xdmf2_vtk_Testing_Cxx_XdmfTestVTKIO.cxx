--- Utilities/Xdmf2/vtk/Testing/Cxx/XdmfTestVTKIO.cxx.orig	2011-04-13 16:17:00.000000000 +0000
+++ Utilities/Xdmf2/vtk/Testing/Cxx/XdmfTestVTKIO.cxx
@@ -21,6 +21,7 @@
 //files around for inspection. Otherwise it deletes the temporary files it
 //creates and returns success.
 
+#include <unistd.h>
 #include "vtkXdmfWriter.h"
 
 #include "vtkCellData.h"
