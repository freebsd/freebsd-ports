--- ext/flac/gstflacenc.c.orig	Tue Mar  8 00:39:55 2005
+++ ext/flac/gstflacenc.c	Tue Mar  8 00:57:34 2005
@@ -475,6 +475,8 @@
   }
 
   gst_pad_push (flacenc->srcpad, GST_DATA (outbuf));
+
+#ifdef FLAC__MAX_METADATA_TYPE_CODE
   flacenc->offset += bytes;
 
   return FLAC__STREAM_ENCODER_OK;
@@ -489,6 +491,8 @@
   *absolute_byte_offset = flacenc->offset;
 
   return FLAC__STREAM_ENCODER_OK;
+
+#endif
 }
 
 static void
@@ -594,8 +598,10 @@
         gst_flacenc_write_callback);
     FLAC__seekable_stream_encoder_set_seek_callback (flacenc->encoder,
         gst_flacenc_seek_callback);
+#ifdef FLAC__MAX_METADATA_TYPE_CODE
     FLAC__seekable_stream_encoder_set_tell_callback (flacenc->encoder,
         gst_flacenc_tell_callback);
+#endif
 
     FLAC__seekable_stream_encoder_set_client_data (flacenc->encoder, flacenc);
 
