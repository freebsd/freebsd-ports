--- modules/efrcodec.cpp.orig	2017-03-28 09:13:48 UTC
+++ modules/efrcodec.cpp
@@ -31,7 +31,19 @@ extern "C" {
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
 
 using namespace TelEngine;
