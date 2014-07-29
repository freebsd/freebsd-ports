--- classes/src/CflowdPacketQueue.cc.orig	Fri Aug 29 21:54:26 2003
+++ classes/src/CflowdPacketQueue.cc	Fri Aug 29 21:58:48 2003
@@ -54,6 +54,7 @@
 #include <syslog.h>
 #include <assert.h>
 
+using namespace std;
 #include "caida_t.h"
 #include "CflowdFlowPdu.h"
   
@@ -401,7 +402,7 @@
 //.........................................................................
 //  
 //-------------------------------------------------------------------------
-int CflowdPacketQueue::GetLock(uint8_t bufNum = 0xff)
+int CflowdPacketQueue::GetLock(uint8_t bufNum)
 {
   if (bufNum == 0xff)
     bufNum = this->_currentBuffer;
@@ -424,7 +425,7 @@
 //.........................................................................
 //  
 //-------------------------------------------------------------------------
-int CflowdPacketQueue::ReleaseLock(uint8_t bufNum = 0xff)
+int CflowdPacketQueue::ReleaseLock(uint8_t bufNum)
 {
   if (bufNum == 0xff)
     bufNum = this->_currentBuffer;
