--- lib/pkt/PktClient.h.orig	2013-06-16 10:55:15.000000000 +0900
+++ lib/pkt/PktClient.h	2013-06-16 10:55:31.000000000 +0900
@@ -46,8 +46,8 @@
 #define	__PktClient_h__	1
 #include "pktDefine.h"
 #include "PktRecv.h"
-struct CmDispatch;
-struct PktClient:public PktReceiver {
+class CmDispatch;
+class PktClient:public PktReceiver {
 private:
 	CmDispatch* dispatch_;
 public:
