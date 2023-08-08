--- OMSimulator/OMTLMSimulator/common/Communication/TLMCommUtil.cc.orig	2022-12-11 03:21:23 UTC
+++ OMSimulator/OMTLMSimulator/common/Communication/TLMCommUtil.cc
@@ -42,7 +42,7 @@ void TLMCommUtil::SendMessage(TLMMessage& mess) {
         TLMCommUtil::ByteSwap(&mess.Header.TLMInterfaceID, sizeof(mess.Header.TLMInterfaceID));
     }
 
-#if defined( WIN32) || defined(__APPLE__)
+#if defined( WIN32) || defined(__APPLE__) || defined(__FreeBSD__)
     const int MSG_MORE = 0;
 #endif
 
