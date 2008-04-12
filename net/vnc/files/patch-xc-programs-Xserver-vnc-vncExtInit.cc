--- xc/programs/Xserver/vnc/vncExtInit.cc.orig	2008-04-12 12:59:39.000000000 +0200
+++ xc/programs/Xserver/vnc/vncExtInit.cc	2008-04-12 12:59:54.000000000 +0200
@@ -751,7 +751,7 @@
   rep.timeout = qcTimeout;
   rep.addrLen = qcTimeout ? strlen(qcAddress) : 0;
   rep.userLen = qcTimeout ? strlen(qcUsername) : 0;
-  rep.opaqueId = (CARD32)queryConnectId;
+  rep.opaqueId = (CARD32)(long)queryConnectId;
   rep.length = (rep.userLen + rep.addrLen + 3) >> 2;
   if (client->swapped) {
     swaps(&rep.sequenceNumber, n);
