--- classes/src/CflowdRawFlow.cc.orig	Fri Aug 29 21:18:36 2003
+++ classes/src/CflowdRawFlow.cc	Fri Aug 29 21:22:55 2003
@@ -44,6 +44,7 @@
 #include <string.h>
 }
 
+using namespace std;
 #include <string>
 
 #include "CflowdRawFlow.hh"
@@ -336,82 +337,82 @@
 
   this->data._isHostOrder = false;
   
-  is.read(&(this->data._index),sizeof(this->data._index));
+  is.read((char *)&(this->data._index),sizeof(this->data._index));
   if (! is)
     return(is);
   flowIndex = ntohl(this->data._index);
 
   if (flowIndex & CflowdRawFlow::k_routerMask) {
-    is.read(&(this->data._router),sizeof(this->data._router));
+    is.read((char *)&(this->data._router),sizeof(this->data._router));
   }
   if (flowIndex & CflowdRawFlow::k_srcIpAddrMask) {
-    is.read(&(this->data._srcIpAddr),sizeof(this->data._srcIpAddr));
+    is.read((char *)&(this->data._srcIpAddr),sizeof(this->data._srcIpAddr));
   }
   if (flowIndex & CflowdRawFlow::k_dstIpAddrMask) {
-    is.read(&(this->data._dstIpAddr),sizeof(this->data._dstIpAddr));
+    is.read((char *)&(this->data._dstIpAddr),sizeof(this->data._dstIpAddr));
   }
   if (flowIndex & CflowdRawFlow::k_inputIfIndexMask) {
-    is.read(&(this->data._inputIfIndex),sizeof(this->data._inputIfIndex));
+    is.read((char *)&(this->data._inputIfIndex),sizeof(this->data._inputIfIndex));
   }
   if (flowIndex & CflowdRawFlow::k_outputIfIndexMask) {
-    is.read(&(this->data._outputIfIndex),sizeof(this->data._outputIfIndex));
+    is.read((char *)&(this->data._outputIfIndex),sizeof(this->data._outputIfIndex));
   }
   if (flowIndex & CflowdRawFlow::k_srcPortMask) {
-    is.read(&(this->data._srcPort),sizeof(this->data._srcPort));
+    is.read((char *)&(this->data._srcPort),sizeof(this->data._srcPort));
   }
   if (flowIndex & CflowdRawFlow::k_dstPortMask) {
-    is.read(&(this->data._dstPort),sizeof(this->data._dstPort));
+    is.read((char *)&(this->data._dstPort),sizeof(this->data._dstPort));
   }
   if (flowIndex & CflowdRawFlow::k_pktsMask) {
-    is.read(&(this->data._pkts),sizeof(this->data._pkts));
+    is.read((char *)&(this->data._pkts),sizeof(this->data._pkts));
   }
   if (flowIndex & CflowdRawFlow::k_bytesMask) {
-    is.read(&(this->data._bytes),sizeof(this->data._bytes));
+    is.read((char *)&(this->data._bytes),sizeof(this->data._bytes));
   }
   if (flowIndex & CflowdRawFlow::k_ipNextHopMask) {
-    is.read(&(this->data._ipNextHop),sizeof(this->data._ipNextHop));
+    is.read((char *)&(this->data._ipNextHop),sizeof(this->data._ipNextHop));
   }
   if (flowIndex & CflowdRawFlow::k_startTimeMask) {
-    is.read(&(this->data._startTime),sizeof(this->data._startTime));
+    is.read((char *)&(this->data._startTime),sizeof(this->data._startTime));
   }
   if (flowIndex & CflowdRawFlow::k_endTimeMask) {
-    is.read(&(this->data._endTime),sizeof(this->data._endTime));
+    is.read((char *)&(this->data._endTime),sizeof(this->data._endTime));
   }
   if (flowIndex & CflowdRawFlow::k_protocolMask) {
-    is.read(&(this->data._protocol),sizeof(this->data._protocol));
+    is.read((char *)&(this->data._protocol),sizeof(this->data._protocol));
   }
   if (flowIndex & CflowdRawFlow::k_tosMask) {
-    is.read(&(this->data._tos),sizeof(this->data._tos));
+    is.read((char *)&(this->data._tos),sizeof(this->data._tos));
   }
   if (flowIndex & CflowdRawFlow::k_srcAsMask) {
-    is.read(&(this->data._srcAs),sizeof(this->data._srcAs));
+    is.read((char *)&(this->data._srcAs),sizeof(this->data._srcAs));
   }
   if (flowIndex & CflowdRawFlow::k_dstAsMask) {
-    is.read(&(this->data._dstAs),sizeof(this->data._dstAs));
+    is.read((char *)&(this->data._dstAs),sizeof(this->data._dstAs));
   }
   if (flowIndex & CflowdRawFlow::k_srcMaskLenMask) {
-    is.read(&(this->data._srcMaskLen),sizeof(this->data._srcMaskLen));
+    is.read((char *)&(this->data._srcMaskLen),sizeof(this->data._srcMaskLen));
   }
   if (flowIndex & CflowdRawFlow::k_dstMaskLenMask) {
-    is.read(&(this->data._dstMaskLen),sizeof(this->data._dstMaskLen));
+    is.read((char *)&(this->data._dstMaskLen),sizeof(this->data._dstMaskLen));
   }
   if (flowIndex & CflowdRawFlow::k_tcpFlagsMask) {
-    is.read(&(this->data._tcpFlags),sizeof(this->data._tcpFlags));
+    is.read((char *)&(this->data._tcpFlags),sizeof(this->data._tcpFlags));
   }
   if (flowIndex & CflowdRawFlow::k_inputEncapMask) {
-    is.read(&(this->data._inputEncap),sizeof(this->data._inputEncap));
+    is.read((char *)&(this->data._inputEncap),sizeof(this->data._inputEncap));
   }
   if (flowIndex & CflowdRawFlow::k_outputEncapMask) {
-    is.read(&(this->data._outputEncap),sizeof(this->data._outputEncap));
+    is.read((char *)&(this->data._outputEncap),sizeof(this->data._outputEncap));
   }
   if (flowIndex & CflowdRawFlow::k_peerNextHopMask) {
-    is.read(&(this->data._peerNextHop),sizeof(this->data._peerNextHop));
+    is.read((char *)&(this->data._peerNextHop),sizeof(this->data._peerNextHop));
   }
   if (flowIndex & CflowdRawFlow::k_engineTypeMask) {
-    is.read(&(this->data._engineType),sizeof(this->data._engineType));
+    is.read((char *)&(this->data._engineType),sizeof(this->data._engineType));
   }
   if (flowIndex & CflowdRawFlow::k_engineIdMask) {
-    is.read(&(this->data._engineId),sizeof(this->data._engineId));
+    is.read((char *)&(this->data._engineId),sizeof(this->data._engineId));
   }
   
   //  convert to host byte order
@@ -982,56 +983,56 @@
   
   rawFlow.ToNetworkByteOrder();
   
-  os.write(&(dataPtr->_index),sizeof(dataPtr->_index));
+  os.write((char *)&(dataPtr->_index),sizeof(dataPtr->_index));
 
   if (flowIndex & CflowdRawFlow::k_routerMask)
-    os.write(&(dataPtr->_router),sizeof(dataPtr->_router));
+    os.write((char *)&(dataPtr->_router),sizeof(dataPtr->_router));
   if (flowIndex & CflowdRawFlow::k_srcIpAddrMask)
-    os.write(&(dataPtr->_srcIpAddr),sizeof(dataPtr->_srcIpAddr));
+    os.write((char *)&(dataPtr->_srcIpAddr),sizeof(dataPtr->_srcIpAddr));
   if (flowIndex & CflowdRawFlow::k_dstIpAddrMask)
-    os.write(&(dataPtr->_dstIpAddr),sizeof(dataPtr->_dstIpAddr));
+    os.write((char *)&(dataPtr->_dstIpAddr),sizeof(dataPtr->_dstIpAddr));
   if (flowIndex & CflowdRawFlow::k_inputIfIndexMask)
-    os.write(&(dataPtr->_inputIfIndex),sizeof(dataPtr->_inputIfIndex));
+    os.write((char *)&(dataPtr->_inputIfIndex),sizeof(dataPtr->_inputIfIndex));
   if (flowIndex & CflowdRawFlow::k_outputIfIndexMask)
-    os.write(&(dataPtr->_outputIfIndex),sizeof(dataPtr->_outputIfIndex));
+    os.write((char *)&(dataPtr->_outputIfIndex),sizeof(dataPtr->_outputIfIndex));
   if (flowIndex & CflowdRawFlow::k_srcPortMask)
-    os.write(&(dataPtr->_srcPort),sizeof(dataPtr->_srcPort));
+    os.write((char *)&(dataPtr->_srcPort),sizeof(dataPtr->_srcPort));
   if (flowIndex & CflowdRawFlow::k_dstPortMask)
-    os.write(&(dataPtr->_dstPort),sizeof(dataPtr->_dstPort));
+    os.write((char *)&(dataPtr->_dstPort),sizeof(dataPtr->_dstPort));
   if (flowIndex & CflowdRawFlow::k_pktsMask)
-    os.write(&(dataPtr->_pkts),sizeof(dataPtr->_pkts));
+    os.write((char *)&(dataPtr->_pkts),sizeof(dataPtr->_pkts));
   if (flowIndex & CflowdRawFlow::k_bytesMask)
-    os.write(&(dataPtr->_bytes),sizeof(dataPtr->_bytes));
+    os.write((char *)&(dataPtr->_bytes),sizeof(dataPtr->_bytes));
   if (flowIndex & CflowdRawFlow::k_ipNextHopMask)
-    os.write(&(dataPtr->_ipNextHop),sizeof(dataPtr->_ipNextHop));
+    os.write((char *)&(dataPtr->_ipNextHop),sizeof(dataPtr->_ipNextHop));
   if (flowIndex & CflowdRawFlow::k_startTimeMask)
-    os.write(&(dataPtr->_startTime),sizeof(dataPtr->_startTime));
+    os.write((char *)&(dataPtr->_startTime),sizeof(dataPtr->_startTime));
   if (flowIndex & CflowdRawFlow::k_endTimeMask)
-    os.write(&(dataPtr->_endTime),sizeof(dataPtr->_endTime));
+    os.write((char *)&(dataPtr->_endTime),sizeof(dataPtr->_endTime));
   if (flowIndex & CflowdRawFlow::k_protocolMask)
-    os.write(&(dataPtr->_protocol),sizeof(dataPtr->_protocol));
+    os.write((char *)&(dataPtr->_protocol),sizeof(dataPtr->_protocol));
   if (flowIndex & CflowdRawFlow::k_tosMask)
-    os.write(&(dataPtr->_tos),sizeof(dataPtr->_tos));
+    os.write((char *)&(dataPtr->_tos),sizeof(dataPtr->_tos));
   if (flowIndex & CflowdRawFlow::k_srcAsMask)
-    os.write(&(dataPtr->_srcAs),sizeof(dataPtr->_srcAs));
+    os.write((char *)&(dataPtr->_srcAs),sizeof(dataPtr->_srcAs));
   if (flowIndex & CflowdRawFlow::k_dstAsMask)
-    os.write(&(dataPtr->_dstAs),sizeof(dataPtr->_dstAs));
+    os.write((char *)&(dataPtr->_dstAs),sizeof(dataPtr->_dstAs));
   if (flowIndex & CflowdRawFlow::k_srcMaskLenMask)
-    os.write(&(dataPtr->_srcMaskLen),sizeof(dataPtr->_srcMaskLen));
+    os.write((char *)&(dataPtr->_srcMaskLen),sizeof(dataPtr->_srcMaskLen));
   if (flowIndex & CflowdRawFlow::k_dstMaskLenMask)
-    os.write(&(dataPtr->_dstMaskLen),sizeof(dataPtr->_dstMaskLen));
+    os.write((char *)&(dataPtr->_dstMaskLen),sizeof(dataPtr->_dstMaskLen));
   if (flowIndex & CflowdRawFlow::k_tcpFlagsMask)
-    os.write(&(dataPtr->_tcpFlags),sizeof(dataPtr->_tcpFlags));
+    os.write((char *)&(dataPtr->_tcpFlags),sizeof(dataPtr->_tcpFlags));
   if (flowIndex & CflowdRawFlow::k_inputEncapMask)
-    os.write(&(dataPtr->_inputEncap),sizeof(dataPtr->_inputEncap));
+    os.write((char *)&(dataPtr->_inputEncap),sizeof(dataPtr->_inputEncap));
   if (flowIndex & CflowdRawFlow::k_outputEncapMask)
-    os.write(&(dataPtr->_outputEncap),sizeof(dataPtr->_outputEncap));
+    os.write((char *)&(dataPtr->_outputEncap),sizeof(dataPtr->_outputEncap));
   if (flowIndex & CflowdRawFlow::k_peerNextHopMask)
-    os.write(&(dataPtr->_peerNextHop),sizeof(dataPtr->_peerNextHop));
+    os.write((char *)&(dataPtr->_peerNextHop),sizeof(dataPtr->_peerNextHop));
   if (flowIndex & CflowdRawFlow::k_engineTypeMask)
-    os.write(&(dataPtr->_engineType),sizeof(dataPtr->_engineType));
+    os.write((char *)&(dataPtr->_engineType),sizeof(dataPtr->_engineType));
   if (flowIndex & CflowdRawFlow::k_engineIdMask)
-    os.write(&(dataPtr->_engineId),sizeof(dataPtr->_engineId));
+    os.write((char *)&(dataPtr->_engineId),sizeof(dataPtr->_engineId));
   
   return(os);
 }
