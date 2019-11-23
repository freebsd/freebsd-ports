--- src/3rdparty/chromium/third_party/webrtc/common_audio/wav_file.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/webrtc/common_audio/wav_file.cc
@@ -93,13 +93,15 @@ size_t WavReader::num_samples() const {
 }
 
 size_t WavReader::ReadSamples(size_t num_samples, int16_t* samples) {
-#ifndef WEBRTC_ARCH_LITTLE_ENDIAN
-#error "Need to convert samples to big-endian when reading from WAV file"
-#endif
   // There could be metadata after the audio; ensure we don't read it.
   num_samples = std::min(num_samples, num_samples_remaining_);
   const size_t read =
       fread(samples, sizeof(*samples), num_samples, file_handle_);
+#ifndef WEBRTC_ARCH_LITTLE_ENDIAN
+  for (size_t i = 0; i < read; i++) {
+      samples[i] = __builtin_bswap16(samples[i]);
+  }
+#endif
   // If we didn't read what was requested, ensure we've reached the EOF.
   RTC_CHECK(read == num_samples || feof(file_handle_));
   RTC_CHECK_LE(read, num_samples_remaining_);
@@ -178,13 +180,26 @@ size_t WavWriter::num_samples() const {
 
 void WavWriter::WriteSamples(const int16_t* samples, size_t num_samples) {
 #ifndef WEBRTC_ARCH_LITTLE_ENDIAN
-#error "Need to convert samples to little-endian when writing to WAV file"
-#endif
+  static const size_t kChunksize = 4096 / sizeof(uint16_t);
+  for (size_t i = 0; i < num_samples; i += kChunksize) {
+    int16_t isamples[kChunksize];
+    const size_t chunk = std::min(kChunksize, num_samples - i);
+    for (size_t j = 0; j < chunk; j++) {
+      isamples[j] = __builtin_bswap16(samples[i + j]);
+    }
+    const size_t written =
+        fwrite(isamples, sizeof(*isamples), chunk, file_handle_);
+    RTC_CHECK_EQ(chunk, written);
+    num_samples_ += written;
+    RTC_CHECK(num_samples_ >= written);  // detect size_t overflow
+  }
+#else
   const size_t written =
       fwrite(samples, sizeof(*samples), num_samples, file_handle_);
   RTC_CHECK_EQ(num_samples, written);
   num_samples_ += written;
   RTC_CHECK(num_samples_ >= written);  // detect size_t overflow
+#endif
 }
 
 void WavWriter::WriteSamples(const float* samples, size_t num_samples) {
