--- ./talk/third_party/mediastreamer/msGSMencoder.h.orig	Thu Mar 16 18:43:06 2006
+++ ./talk/third_party/mediastreamer/msGSMencoder.h	Fri Apr 21 10:56:34 2006
@@ -36,7 +36,7 @@
        in order to the object mechanism to work*/
     MSFilter filter;
     MSFifo *f_inputs[MSGSMENCODER_MAX_INPUTS];
-    MSFifo *f_outputs[MSGSMENCODER_MAX_INPUTS];
+    MSQueue *q_outputs[MSGSMENCODER_MAX_INPUTS];
     gsm gsm_handle;
 } MSGSMEncoder;
 
