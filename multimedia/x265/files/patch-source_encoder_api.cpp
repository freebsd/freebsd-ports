source/encoder/api.cpp:432:17: error: cannot jump from this
      goto statement to its label
                goto fail;
                ^
source/encoder/api.cpp:436:36: note: jump bypasses variable
      initialization
        EB_H265_ENC_CONFIGURATION* svtParam = (EB_H265_ENC_CONFIGURATION*)encoder->m_svtAppData->svtHevcParams;
                                   ^
source/encoder/api.cpp:413:17: error: cannot jump from this
      goto statement to its label
                goto fail;
                ^
source/encoder/api.cpp:436:36: note: jump bypasses variable
      initialization
        EB_H265_ENC_CONFIGURATION* svtParam = (EB_H265_ENC_CONFIGURATION*)encoder->m_svtAppData->svtHevcParams;
                                   ^
source/encoder/api.cpp:406:21: error: cannot jump from this
      goto statement to its label
                    goto fail;
                    ^
source/encoder/api.cpp:436:36: note: jump bypasses variable
      initialization
        EB_H265_ENC_CONFIGURATION* svtParam = (EB_H265_ENC_CONFIGURATION*)encoder->m_svtAppData->svtHevcParams;
                                   ^
3 errors generated.

--- source/encoder/api.cpp.orig	2019-01-23 09:47:18 UTC
+++ source/encoder/api.cpp
@@ -355,6 +355,7 @@ int x265_encoder_encode(x265_encoder *enc, x265_nal **
     static unsigned char picSendDone = 0;
     numEncoded = 0;
     static int codedNal = 0, eofReached = 0;
+    EB_H265_ENC_CONFIGURATION* svtParam = NULL;
 
     if (encoder->m_param->bEnableSvtHevc)
     {
@@ -433,7 +434,7 @@ int x265_encoder_encode(x265_encoder *enc, x265_nal **
             }
         }
 
-        EB_H265_ENC_CONFIGURATION* svtParam = (EB_H265_ENC_CONFIGURATION*)encoder->m_svtAppData->svtHevcParams;
+        svtParam = (EB_H265_ENC_CONFIGURATION*)encoder->m_svtAppData->svtHevcParams;
         if (eofReached && svtParam->codeEosNal == 0 && !codedNal)
         {
             EB_BUFFERHEADERTYPE *outputStreamPtr = 0;
