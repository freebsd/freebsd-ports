--- ext/flac/gstflacdec.c.orig	Thu Jul 11 21:35:29 2002
+++ ext/flac/gstflacdec.c	Thu Jul 11 21:44:42 2002
@@ -74,10 +74,10 @@
 							 void *client_data);
 static FLAC__StreamDecoderWriteStatus 	
 			gst_flacdec_write 		(const FLAC__SeekableStreamDecoder *decoder, 
-							 const FLAC__Frame *frame, const FLAC__int32 *buffer[], 
+							 const FLAC__Frame *frame, const FLAC__int32 * const buffer[],
 							 void *client_data);
 static void 		gst_flacdec_metadata_callback 	(const FLAC__SeekableStreamDecoder *decoder, 
-							 const FLAC__StreamMetaData *metadata, 
+							 const FLAC__StreamMetadata *metadata,
 							 void *client_data);
 static void 		gst_flacdec_error_callback 	(const FLAC__SeekableStreamDecoder *decoder, 
 							 FLAC__StreamDecoderErrorStatus status, 
@@ -152,7 +152,7 @@
 
 static void 
 gst_flacdec_metadata_callback (const FLAC__SeekableStreamDecoder *decoder,
-			       const FLAC__StreamMetaData *metadata, void *client_data)
+			       const FLAC__StreamMetadata *metadata, void *client_data)
 {
   FlacDec *flacdec;
 
@@ -171,13 +171,13 @@
   flacdec = GST_FLACDEC (client_data);
 
   switch (status) {
-    case FLAC__STREAM_DECODER_ERROR_LOST_SYNC:
+    case FLAC__STREAM_DECODER_ERROR_STATUS_LOST_SYNC:
       error = "lost sync";
       break;
-    case FLAC__STREAM_DECODER_ERROR_BAD_HEADER:
+    case FLAC__STREAM_DECODER_ERROR_STATUS_BAD_HEADER:
       error = "bad header";
       break;
-    case FLAC__STREAM_DECODER_ERROR_FRAME_CRC_MISMATCH:
+    case FLAC__STREAM_DECODER_ERROR_STATUS_FRAME_CRC_MISMATCH:
       error = "CRC mismatch";
       break;
     default:
@@ -271,6 +271,7 @@
           GST_DEBUG (0, "eos");
           flacdec->eos = TRUE; 
           if (avail == 0) {
+	    gst_event_free (event);
             return 0;
           }
           break;
@@ -301,7 +302,7 @@
 
 static FLAC__StreamDecoderWriteStatus
 gst_flacdec_write (const FLAC__SeekableStreamDecoder *decoder, const FLAC__Frame *frame, 
-		   const FLAC__int32 *buffer[], void *client_data)
+		   const FLAC__int32 * const buffer[], void *client_data)
 {
   FlacDec *flacdec;
   GstBuffer *outbuf;
@@ -383,14 +384,14 @@
   }
   else {
     g_warning ("flacdec: invalid depth %d found\n", depth);
-    return FLAC__STREAM_DECODER_WRITE_ABORT;
+    return FLAC__STREAM_DECODER_WRITE_STATUS_ABORT;
   }
 
   flacdec->total_samples += samples;
 
   gst_pad_push (flacdec->srcpad, outbuf);
 
-  return FLAC__STREAM_DECODER_WRITE_CONTINUE;
+  return FLAC__STREAM_DECODER_WRITE_STATUS_CONTINUE;
 }
 
 static void 
@@ -554,6 +555,7 @@
       res = FALSE;
       break;
   }
+  gst_event_free (event);
   return res;
 }
 
