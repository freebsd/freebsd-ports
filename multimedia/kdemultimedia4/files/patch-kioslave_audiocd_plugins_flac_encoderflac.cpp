--- kioslave/audiocd/plugins/flac/encoderflac.cpp.orig	2006-01-19 17:40:33.000000000 +0100
+++ kioslave/audiocd/plugins/flac/encoderflac.cpp	2008-03-27 18:03:56.000000000 +0100
@@ -47,7 +47,7 @@ public:
     unsigned long data;
 };
 
-static FLAC__StreamEncoderWriteStatus WriteCallback(const FLAC__StreamEncoder *encoder, const FLAC__byte buffer[], unsigned bytes, unsigned samples, unsigned current_frame, void *client_data)
+static FLAC__StreamEncoderWriteStatus WriteCallback(const FLAC__StreamEncoder *encoder, const FLAC__byte buffer[], size_t bytes, unsigned samples, unsigned current_frame, void *client_data)
 {
     EncoderFLAC::Private *d = (EncoderFLAC::Private*)client_data;
 
@@ -109,9 +109,6 @@ unsigned long EncoderFLAC::size(long tim
 long EncoderFLAC::readInit(long size) {
     kdDebug(7117) << "EncoderFLAC::readInit() called"<< endl;
     d->data = 0;
-    FLAC__stream_encoder_set_write_callback(d->encoder, WriteCallback);
-    FLAC__stream_encoder_set_metadata_callback(d->encoder, MetadataCallback);
-    FLAC__stream_encoder_set_client_data(d->encoder, d);
 
     // The options match approximely those of flac compression-level-3
     FLAC__stream_encoder_set_do_mid_side_stereo(d->encoder, true);
@@ -124,7 +121,7 @@ long EncoderFLAC::readInit(long size) {
     if (size > 0)
         FLAC__stream_encoder_set_total_samples_estimate(d->encoder, size/4);
 
-    FLAC__stream_encoder_init(d->encoder);
+    FLAC__stream_encoder_init_stream(d->encoder, WriteCallback, NULL, NULL, MetadataCallback, d);
     return d->data;
 }
 
