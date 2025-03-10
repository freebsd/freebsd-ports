--- modules/amrnbcodec.cpp.orig	2017-08-14 12:53:31 UTC
+++ modules/amrnbcodec.cpp
@@ -30,7 +30,19 @@ extern "C" {
 }
 namespace RxTypes {
 // There is a conflict between encoder and decoder so insulate in a namespace
-#include <sp_dec.h>
+extern "C" {
+    // copied from ${WRKSRC}/opencore/codecs_v2/audio/gsm_amr/amr_nb/common/include/frame.h of audio/opencore-amr
+    enum RXFrameType { RX_SPEECH_GOOD = 0,
+        RX_SPEECH_DEGRADED,
+        RX_ONSET,
+        RX_SPEECH_BAD,
+        RX_SID_FIRST,
+        RX_SID_UPDATE,
+        RX_SID_BAD,
+        RX_NO_DATA,
+        RX_N_FRAMETYPES     /* number of frame types */
+    };
+}
 };
 
 // IF1/GP3 is Bandwidth-Efficient Mode
