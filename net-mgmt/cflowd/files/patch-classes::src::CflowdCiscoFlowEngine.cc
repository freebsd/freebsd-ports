--- classes/src/CflowdCiscoFlowEngine.cc.orig	Fri Aug 29 21:13:33 2003
+++ classes/src/CflowdCiscoFlowEngine.cc	Fri Aug 29 21:17:18 2003
@@ -43,6 +43,7 @@
 #include "caida_t.h"
 }
 
+using namespace std;
 #include <string>
 
 #include "CflowdCiscoFlowEngine.hh"
@@ -58,7 +59,7 @@
 //-------------------------------------------------------------------------
 uint32_t CflowdCiscoFlowEngine::SequenceNumber(uint32_t seqNumber,
                                                uint16_t flowCount,
-                                               uint8_t aggMethod = 0)
+                                               uint8_t aggMethod )
 {
   if (aggMethod > k_CiscoV8FlowExportMaxAggType) {
     syslog(LOG_ERR,
