--- classes/include/CflowdCisco.hh.orig	Fri Aug 29 20:49:59 2003
+++ classes/include/CflowdCisco.hh	Fri Aug 29 20:53:49 2003
@@ -48,6 +48,8 @@
 #include "caida_t.h"
 }
 
+using namespace std;
+
 #include "CflowdRawFlow.hh"
 #include "CflowdRawFlowLogger.hh"
 #include "CflowdCiscoFlowInterfaceMap.hh"
