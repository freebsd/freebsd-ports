--- libavcodec/libilbc.c.orig	2016-05-25 00:36:32 UTC
+++ libavcodec/libilbc.c
@@ -20,6 +20,7 @@
  */
 
 #include <ilbc.h>
+#include <stdint.h>
 
 #include "libavutil/channel_layout.h"
 #include "libavutil/common.h"
@@ -95,8 +96,8 @@ static int ilbc_decode_frame(AVCodecCont
         return ret;
     }
 
-    WebRtcIlbcfix_DecodeImpl((WebRtc_Word16*) frame->data[0],
-                             (const WebRtc_UWord16*) buf, &s->decoder, 1);
+    WebRtcIlbcfix_DecodeImpl((int16_t*) frame->data[0],
+                             (const uint16_t*) buf, &s->decoder, 1);
 
     *got_frame_ptr = 1;
 
@@ -168,7 +169,7 @@ static int ilbc_encode_frame(AVCodecCont
         return ret;
     }
 
-    WebRtcIlbcfix_EncodeImpl((WebRtc_UWord16*) avpkt->data, (const WebRtc_Word16*) frame->data[0], &s->encoder);
+    WebRtcIlbcfix_EncodeImpl((uint16_t*) avpkt->data, (const int16_t*) frame->data[0], &s->encoder);
 
     avpkt->size     = s->encoder.no_of_bytes;
     *got_packet_ptr = 1;
