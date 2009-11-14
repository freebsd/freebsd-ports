--- plugins/audio/celt/celtcodec.c.orig	2009-09-22 02:57:45.000000000 +0200
+++ plugins/audio/celt/celtcodec.c	2009-11-13 22:00:39.000000000 +0100
@@ -52,7 +52,7 @@ static int init_mode(CELTContext *celt, 
 {
   int error = 0;
 
-  celt->mode = celt_mode_create(codec->sampleRate, 1, codec->parm.audio.samplesPerFrame, &error);
+  celt->mode = celt_mode_create(codec->sampleRate, codec->parm.audio.samplesPerFrame, &error);
   if (celt->mode == NULL) {
     return FALSE;
   }
@@ -74,7 +74,7 @@ static void * celt_create_encoder(const 
     return NULL;
   }
  	
-  celt->encoder_state = celt_encoder_create(celt->mode);
+  celt->encoder_state = celt_encoder_create(celt->mode, 1, NULL);
   if (celt->encoder_state == NULL ) {
     celt_mode_destroy(celt->mode);
     free(celt);
@@ -96,7 +96,7 @@ static void * celt_create_decoder(const 
     return NULL;
   }
 
-  celt->decoder_state = celt_decoder_create(celt->mode);
+  celt->decoder_state = celt_decoder_create(celt->mode, 1, NULL);
   if (celt->decoder_state == NULL ) {
     celt_mode_destroy(celt->mode);
     free(celt);
@@ -143,9 +143,9 @@ static int celt_codec_encoder(const stru
     return FALSE;
 
 #ifdef HAVE_CELT_0_5_0_OR_LATER
-  byteCount = celt_encode(celt->encoder_state, (celt_int16_t *)fromPtr, NULL, (char *)toPtr, celt->bytes_per_packet);
+  byteCount = celt_encode(celt->encoder_state, (celt_int16 *)fromPtr, NULL, (char *)toPtr, celt->bytes_per_packet);
 #else
-  byteCount = celt_encode(celt->encoder_state, (celt_int16_t *)fromPtr, (char *)toPtr, celt->bytes_per_packet);
+  byteCount = celt_encode(celt->encoder_state, (celt_int16 *)fromPtr, (char *)toPtr, celt->bytes_per_packet);
 #endif
   if (byteCount < 0) {
 	return 0;
