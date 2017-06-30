--- codec_g72x.c.orig	2016-10-05 19:27:27 UTC
+++ codec_g72x.c
@@ -215,7 +215,7 @@ static int lintog72x_new(struct ast_trans_pvt *pvt)
         apiG723Encoder_Init(state->coder, G723Encode_DefaultMode);
     #endif
 #else
-    state->coder = initBcg729EncoderChannel();
+    state->coder = initBcg729EncoderChannel(0);
 #endif
     return 0;
 }
@@ -320,7 +320,7 @@ static int g72xtolin_framein(struct ast_trans_pvt *pvt
 #if !G72X_BCG729
         apiG729Decode(state->coder, (unsigned char *)lost_frame, g729_frame_type(0), dst + pvt->samples);
 #else
-        bcg729Decoder(state->coder, (unsigned char *)lost_frame, 1, dst + pvt->samples);
+        bcg729Decoder(state->coder, (unsigned char *)lost_frame, 0, 1, 0, 0, dst + pvt->samples);
 #endif
         pvt->samples += G729_SAMPLES;
         pvt->datalen += 2 * G729_SAMPLES; /* 2 bytes/sample */
@@ -339,7 +339,7 @@ static int g72xtolin_framein(struct ast_trans_pvt *pvt
 #if !G72X_BCG729
         apiG729Decode(state->coder, (unsigned char *)f->FRAME_DATA + x, g729_frame_type(framesize), dst + pvt->samples);
 #elif G72X_9
-        bcg729Decoder(state->coder, (unsigned char *)f->FRAME_DATA + x, 0, dst + pvt->samples);
+        bcg729Decoder(state->coder, (unsigned char *)f->FRAME_DATA + x, 0, 0, framesize == 2 ? 1 : 0, 0, dst + pvt->samples);
 #endif
         pvt->samples += G729_SAMPLES;
         pvt->datalen += 2*G729_SAMPLES;
@@ -447,8 +447,9 @@ static struct ast_frame *lintog72x_frameout(struct ast
         datalen += (g723_sendrate == G723_RATE_63) ? 24 : 20;
     #endif
 #else
-        bcg729Encoder(state->coder, state->buf + samples, (unsigned char *)(pvt->OUTBUF_G72X) + datalen);
-        datalen += G729_FRAME_LEN;
+        uint8_t framesize;
+        bcg729Encoder(state->coder, state->buf + samples, (unsigned char *)(pvt->OUTBUF_G72X) + datalen, &framesize);
+        datalen += framesize; // VAD is disabled, it's G729_FRAME_LEN
 #endif
         samples += G72X_SAMPLES;
         pvt->samples -= G72X_SAMPLES;
