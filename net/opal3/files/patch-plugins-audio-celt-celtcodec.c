--- ./plugins/audio/celt/celtcodec.c.orig	2009-09-22 02:57:45.000000000 +0200
+++ ./plugins/audio/celt/celtcodec.c	2011-04-12 12:26:00.485668577 +0200
@@ -52,12 +52,12 @@
 {
   int error = 0;
 
-  celt->mode = celt_mode_create(codec->sampleRate, 1, codec->parm.audio.samplesPerFrame, &error);
+  celt->mode = celt_mode_create(codec->sampleRate, codec->parm.audio.samplesPerFrame, &error);
   if (celt->mode == NULL) {
     return FALSE;
   }
 
-  celt_mode_info(celt->mode, CELT_GET_FRAME_SIZE, &celt->frame_size);
+  celt->frame_size = 960; /* default from tools/celtenc.c */
   celt->bytes_per_packet = (codec->bitsPerSec * celt->frame_size/codec->sampleRate + 4) / 8;
 
   return TRUE;
@@ -74,7 +74,7 @@
     return NULL;
   }
  	
-  celt->encoder_state = celt_encoder_create(celt->mode);
+  celt->encoder_state = celt_encoder_create(celt->mode, 1, NULL);
   if (celt->encoder_state == NULL ) {
     celt_mode_destroy(celt->mode);
     free(celt);
@@ -96,7 +96,7 @@
     return NULL;
   }
 
-  celt->decoder_state = celt_decoder_create(celt->mode);
+  celt->decoder_state = celt_decoder_create(celt->mode, 1, NULL);
   if (celt->decoder_state == NULL ) {
     celt_mode_destroy(celt->mode);
     free(celt);
@@ -143,9 +143,9 @@
     return FALSE;
 
 #ifdef HAVE_CELT_0_5_0_OR_LATER
-  byteCount = celt_encode(celt->encoder_state, (celt_int16_t *)fromPtr, NULL, (char *)toPtr, celt->bytes_per_packet);
+  byteCount = celt_encode(celt->encoder_state, (celt_int16 *)fromPtr, celt->frame_size, (char *)toPtr, celt->bytes_per_packet);
 #else
-  byteCount = celt_encode(celt->encoder_state, (celt_int16_t *)fromPtr, (char *)toPtr, celt->bytes_per_packet);
+  byteCount = celt_encode(celt->encoder_state, (celt_int16 *)fromPtr, (char *)toPtr, celt->bytes_per_packet);
 #endif
   if (byteCount < 0) {
 	return 0;
@@ -173,7 +173,7 @@
   if (*fromLen == 0)
     return FALSE;
 
-  if (celt_decode(celt->decoder_state, (char *)fromPtr, *fromLen, (short *)toPtr) < 0) {
+  if (celt_decode(celt->decoder_state, (char *)fromPtr, *fromLen, (short *)toPtr, celt->frame_size) < 0) {
     return 0;
   }
 
