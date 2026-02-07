--- src/3rdparty/chromium/media/formats/mp4/box_definitions.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/media/formats/mp4/box_definitions.cc
@@ -1107,15 +1107,14 @@ bool OpusSpecificBox::Parse(BoxReader* reader) {
   RCHECK(reader->Read4(&sample_rate));
   RCHECK(reader->Read2s(&gain_db));
 
-#if !defined(ARCH_CPU_LITTLE_ENDIAN)
-#error The code below assumes little-endianness.
-#endif
-
-  memcpy(&extradata[OPUS_EXTRADATA_SKIP_SAMPLES_OFFSET], &codec_delay_in_frames,
-         sizeof(codec_delay_in_frames));
-  memcpy(&extradata[OPUS_EXTRADATA_SAMPLE_RATE_OFFSET], &sample_rate,
-         sizeof(sample_rate));
-  memcpy(&extradata[OPUS_EXTRADATA_GAIN_OFFSET], &gain_db, sizeof(gain_db));
+  extradata[OPUS_EXTRADATA_SKIP_SAMPLES_OFFSET] = (codec_delay_in_frames >> 0) & 0xff;
+  extradata[OPUS_EXTRADATA_SKIP_SAMPLES_OFFSET+1] = (codec_delay_in_frames >> 8) & 0xff;
+  extradata[OPUS_EXTRADATA_SAMPLE_RATE_OFFSET] = (sample_rate >> 0) & 0xff;
+  extradata[OPUS_EXTRADATA_SAMPLE_RATE_OFFSET+1] = (sample_rate >> 8) & 0xff;
+  extradata[OPUS_EXTRADATA_SAMPLE_RATE_OFFSET+2] = (sample_rate >> 16) & 0xff;
+  extradata[OPUS_EXTRADATA_SAMPLE_RATE_OFFSET+3] = (sample_rate >> 24) & 0xff;
+  extradata[OPUS_EXTRADATA_GAIN_OFFSET] = (gain_db >> 0) & 0xff;
+  extradata[OPUS_EXTRADATA_GAIN_OFFSET+1] = (gain_db >> 8) & 0xff;
 
   channel_count = extradata[OPUS_EXTRADATA_CHANNELS_OFFSET];
 
