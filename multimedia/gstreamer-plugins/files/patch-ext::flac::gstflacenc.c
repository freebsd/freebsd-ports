--- ext/flac/gstflacenc.c.orig	Thu Jul 11 21:17:58 2002
+++ ext/flac/gstflacenc.c	Thu Jul 11 21:33:45 2002
@@ -56,7 +56,7 @@
 static FLAC__StreamEncoderWriteStatus 
 		gst_flacenc_write_callback 	(const FLAC__StreamEncoder *encoder, const FLAC__byte buffer[], unsigned bytes, 
 			    			 unsigned samples, unsigned current_frame, void *client_data);
-static void 	gst_flacenc_metadata_callback 	(const FLAC__StreamEncoder *encoder, const FLAC__StreamMetaData *metadata, 
+static void	gst_flacenc_metadata_callback	(const FLAC__StreamEncoder *encoder, const FLAC__StreamMetadata *metadata,
 						 void *client_data);
 
 static GstElementClass *parent_class = NULL;
@@ -170,7 +170,7 @@
 }
 
 static void 
-gst_flacenc_metadata_callback (const FLAC__StreamEncoder *encoder, const FLAC__StreamMetaData *metadata, void *client_data)
+gst_flacenc_metadata_callback (const FLAC__StreamEncoder *encoder, const FLAC__StreamMetadata *metadata, void *client_data)
 {
   GstEvent *event;
   FlacEnc *flacenc;
