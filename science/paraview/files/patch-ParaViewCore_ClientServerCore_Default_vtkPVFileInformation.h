--- ParaViewCore/ClientServerCore/Default/vtkPVFileInformation.h.orig	2018-06-01 19:23:15 UTC
+++ ParaViewCore/ClientServerCore/Default/vtkPVFileInformation.h
@@ -31,6 +31,7 @@
 #include "vtkPVInformation.h"
 
 #include <string> // Needed for std::string
+#include <time.h>
 
 class vtkCollection;
 class vtkPVFileInformationSet;
