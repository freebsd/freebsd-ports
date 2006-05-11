--- ./talk/third_party/mediastreamer/mscodec.c.orig	Thu May 11 00:01:12 2006
+++ ./talk/third_party/mediastreamer/mscodec.c	Thu May 11 00:01:45 2006
@@ -21,6 +21,7 @@
 
 #include "mscodec.h"
 #include "msMUlawdec.h"
+#include "msAlawdec.h"
 
 #ifdef TRUESPEECH
 extern MSCodecInfo TrueSpeechinfo;
@@ -43,6 +44,7 @@
 //	ms_filter_register(MS_FILTER_INFO(&GSMinfo));
 //	ms_filter_register(MS_FILTER_INFO(&LPC10info));
 	ms_filter_register(MS_FILTER_INFO(&MULAWinfo));
+	ms_filter_register(MS_FILTER_INFO(&ALAWinfo));
 #ifdef TRUESPEECH
         ms_filter_register(MS_FILTER_INFO(&TrueSpeechinfo));
 #endif
