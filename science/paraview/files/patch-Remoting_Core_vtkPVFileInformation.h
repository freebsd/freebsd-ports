--- Remoting/Core/vtkPVFileInformation.h.orig	2024-02-28 20:42:21 UTC
+++ Remoting/Core/vtkPVFileInformation.h
@@ -19,6 +19,7 @@
 #include "vtkRemotingCoreModule.h" //needed for exports
 
 #include <string> // Needed for std::string
+#include <time.h>
 
 class vtkCollection;
 class vtkPVFileInformationSet;
