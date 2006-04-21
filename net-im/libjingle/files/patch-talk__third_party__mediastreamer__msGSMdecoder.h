--- ./talk/third_party/mediastreamer/msGSMdecoder.h.orig	Thu Mar 16 18:43:06 2006
+++ ./talk/third_party/mediastreamer/msGSMdecoder.h	Fri Apr 21 10:56:34 2006
@@ -36,7 +36,7 @@
     /* the MSGSMDecoder derivates from MSFilter, so the MSFilter object MUST be the first of the MSGSMDecoder object
        in order to the object mechanism to work*/
     MSFilter filter;
-    MSFifo *f_inputs[MSGSMDECODER_MAX_INPUTS];
+    MSQueue *q_inputs[MSGSMDECODER_MAX_INPUTS];
     MSFifo *f_outputs[MSGSMDECODER_MAX_INPUTS];
     gsm gsm_handle;
 } MSGSMDecoder;
