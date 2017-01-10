--- ParaViewCore/ClientServerCore/Default/vtkPVFileInformation.h.orig	2016-11-14 15:41:57 UTC
+++ ParaViewCore/ClientServerCore/Default/vtkPVFileInformation.h
@@ -30,6 +30,8 @@
 #include "vtkPVClientServerCoreDefaultModule.h" //needed for exports
 #include "vtkPVInformation.h"
 
+#include <time.h>
+
 class vtkCollection;
 class vtkPVFileInformationSet;
 class vtkFileSequenceParser;
