--- Remoting/Core/vtkPVFileInformation.h.orig	2022-03-11 22:19:30 UTC
+++ Remoting/Core/vtkPVFileInformation.h
@@ -31,6 +31,7 @@
 #include "vtkRemotingCoreModule.h" //needed for exports
 
 #include <string> // Needed for std::string
+#include <time.h>
 
 class vtkCollection;
 class vtkPVFileInformationSet;
