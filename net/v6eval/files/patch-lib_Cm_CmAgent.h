--- lib/Cm/CmAgent.h.orig	2013-06-16 10:41:30.000000000 +0900
+++ lib/Cm/CmAgent.h	2013-06-16 10:42:30.000000000 +0900
@@ -46,11 +46,11 @@
 #define _Cm_CmAgent_h_	1
 /* Interface Definition */
 #include "CmReceiver.h"
-struct CmAgent;
+class CmAgent;
 typedef int (CmAgent::*agentFunc)(int);
 typedef int (CmAgent::*timerFunc)(time_t,uint32_t);
-struct CmDispatch;
-struct CmAgent:public CmReceiver {
+class CmDispatch;
+class CmAgent:public CmReceiver {
 private:
 	agentFunc readAction_;
 	agentFunc writeAction_;
