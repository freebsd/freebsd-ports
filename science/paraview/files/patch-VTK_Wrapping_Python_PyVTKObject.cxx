--- VTK/Wrapping/Python/PyVTKObject.cxx.orig	2011-04-13 16:17:36.000000000 +0000
+++ VTK/Wrapping/Python/PyVTKObject.cxx
@@ -28,6 +28,7 @@
   it is removed along with the smart pointer from the ObjectMap.
 -----------------------------------------------------------------------*/
 
+#include <cstddef>
 #include "PyVTKObject.h"
 #include "vtkPythonUtil.h"
 #include "vtkObjectBase.h"
