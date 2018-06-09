--- ParaViewCore/ClientServerCore/Default/vtkPVFileInformation.h.orig	2018-05-31 23:28:45.128756000 +0700
+++ ParaViewCore/ClientServerCore/Default/vtkPVFileInformation.h	2018-05-31 23:28:56.798284000 +0700
@@ -31,6 +31,7 @@
 #include "vtkPVInformation.h"
 
 #include <string> // Needed for std::string
+#include <time.h>
 
 class vtkCollection;
 class vtkPVFileInformationSet;
