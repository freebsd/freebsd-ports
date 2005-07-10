--- APIModules/QTSSReflectorModule/ReflectorStream.cpp.orig	Thu Sep 30 23:40:54 2004
+++ APIModules/QTSSReflectorModule/ReflectorStream.cpp	Sun Jul 10 15:16:15 2005
@@ -381,11 +381,11 @@
     // specified by the source info, we can use that to demultiplex separate broadcasts on
     // the same port. If the src IP addr is 0, we cannot do this and must dedicate 1 port per
     // broadcast
-    fSockets = sSocketPool.GetUDPSocketPair(INADDR_ANY, fStreamInfo.fPort, fStreamInfo.fSrcIPAddr, 0);
+    fSockets = sSocketPool.GetUDPSocketPair(fStreamInfo.fDestIPAddr, fStreamInfo.fPort, fStreamInfo.fSrcIPAddr, 0);
     if ((fSockets == NULL) && fStreamInfo.fSetupToReceive)
     {
         fStreamInfo.fPort = 0;
-        fSockets = sSocketPool.GetUDPSocketPair(INADDR_ANY, fStreamInfo.fPort, fStreamInfo.fSrcIPAddr, 0);
+        fSockets = sSocketPool.GetUDPSocketPair(fStreamInfo.fDestIPAddr, fStreamInfo.fPort, fStreamInfo.fSrcIPAddr, 0);
     }
     if (fSockets == NULL)
         return QTSSModuleUtils::SendErrorResponse(inRequest, qtssServerInternal,
@@ -1388,7 +1388,7 @@
         {   
             // Check to see if we need to set the remote RTCP address
             // for this stream. This will be necessary if the source is unicast.
-            if ((theRemoteAddr != 0) && (theSender->fStream->fDestRTCPAddr == 0))
+            if ((theRemoteAddr != 0) && (theSender->fStream->fDestRTCPAddr == 0) && (thePacket->IsRTCP()))
             {
                 // If the source is multicast, this shouldn't be necessary
                 Assert(!SocketUtils::IsMulticastIPAddr(theSender->fStream->fStreamInfo.fDestIPAddr));
