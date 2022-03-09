--- src/common_audio/wav_file.cc.orig	2022-02-09 19:21:53 UTC
+++ src/common_audio/wav_file.cc
@@ -14,6 +14,7 @@
 
 #include <algorithm>
 #include <array>
+#include <sys/endian.h>
 #include <cstdio>
 #include <type_traits>
 #include <utility>
@@ -89,10 +90,6 @@ void WavReader::Reset() {
 
 size_t WavReader::ReadSamples(const size_t num_samples,
                               int16_t* const samples) {
-#ifndef WEBRTC_ARCH_LITTLE_ENDIAN
-#error "Need to convert samples to big-endian when reading from WAV file"
-#endif
-
   size_t num_samples_left_to_read = num_samples;
   size_t next_chunk_start = 0;
   while (num_samples_left_to_read > 0 && num_unread_samples_ > 0) {
@@ -124,15 +121,16 @@ size_t WavReader::ReadSamples(const size_t num_samples
     num_unread_samples_ -= num_samples_read;
     num_samples_left_to_read -= num_samples_read;
   }
+#ifndef WEBRTC_ARCH_LITTLE_ENDIAN
+  for (size_t i = 0; i < num_samples; i++) {
+    samples[i] = bswap16(samples[i]);
+  }
+#endif
 
   return num_samples - num_samples_left_to_read;
 }
 
 size_t WavReader::ReadSamples(const size_t num_samples, float* const samples) {
-#ifndef WEBRTC_ARCH_LITTLE_ENDIAN
-#error "Need to convert samples to big-endian when reading from WAV file"
-#endif
-
   size_t num_samples_left_to_read = num_samples;
   size_t next_chunk_start = 0;
   while (num_samples_left_to_read > 0 && num_unread_samples_ > 0) {
@@ -170,6 +168,12 @@ size_t WavReader::ReadSamples(const size_t num_samples
     num_unread_samples_ -= num_samples_read;
     num_samples_left_to_read -= num_samples_read;
   }
+#ifndef WEBRTC_ARCH_LITTLE_ENDIAN
+  // TODO: is this the right place for this?
+  for (size_t i = 0; i < num_samples; i++) {
+    samples[i] = bswap16(samples[i]);
+  }
+#endif
 
   return num_samples - num_samples_left_to_read;
 }
@@ -213,23 +217,33 @@ WavWriter::WavWriter(FileWrapper file,
 }
 
 void WavWriter::WriteSamples(const int16_t* samples, size_t num_samples) {
-#ifndef WEBRTC_ARCH_LITTLE_ENDIAN
-#error "Need to convert samples to little-endian when writing to WAV file"
-#endif
-
   for (size_t i = 0; i < num_samples; i += kMaxChunksize) {
     const size_t num_remaining_samples = num_samples - i;
     const size_t num_samples_to_write =
         std::min(kMaxChunksize, num_remaining_samples);
 
     if (format_ == WavFormat::kWavFormatPcm) {
+#ifndef WEBRTC_ARCH_LITTLE_ENDIAN
       RTC_CHECK(
           file_.Write(&samples[i], num_samples_to_write * sizeof(samples[0])));
+#else
+      std::array<int16_t, kMaxChunksize> converted_samples;
+      for (size_t j = 0; j < num_samples_to_write; ++j) {
+        converted_samples[j] = bswap16(samples[i + j]);
+      }
+      RTC_CHECK(
+          file_.Write(converted_samples.data(),
+                      num_samples_to_write * sizeof(converted_samples[0])));
+#endif
     } else {
       RTC_CHECK_EQ(format_, WavFormat::kWavFormatIeeeFloat);
       std::array<float, kMaxChunksize> converted_samples;
       for (size_t j = 0; j < num_samples_to_write; ++j) {
-        converted_samples[j] = S16ToFloat(samples[i + j]);
+        int16_t sample = samples[i + j];
+#ifndef WEBRTC_ARCH_LITTLE_ENDIAN
+        sample = bswap16(sample);
+#endif
+        converted_samples[j] = S16ToFloat(sample);
       }
       RTC_CHECK(
           file_.Write(converted_samples.data(),
@@ -243,10 +257,6 @@ void WavWriter::WriteSamples(const int16_t* samples, s
 }
 
 void WavWriter::WriteSamples(const float* samples, size_t num_samples) {
-#ifndef WEBRTC_ARCH_LITTLE_ENDIAN
-#error "Need to convert samples to little-endian when writing to WAV file"
-#endif
-
   for (size_t i = 0; i < num_samples; i += kMaxChunksize) {
     const size_t num_remaining_samples = num_samples - i;
     const size_t num_samples_to_write =
@@ -255,7 +265,11 @@ void WavWriter::WriteSamples(const float* samples, siz
     if (format_ == WavFormat::kWavFormatPcm) {
       std::array<int16_t, kMaxChunksize> converted_samples;
       for (size_t j = 0; j < num_samples_to_write; ++j) {
-        converted_samples[j] = FloatS16ToS16(samples[i + j]);
+        int16_t sample = FloatS16ToS16(samples[i + j]);
+#ifndef WEBRTC_ARCH_LITTLE_ENDIAN
+        sample = bswap16(sample);
+#endif
+        converted_samples[j] = sample;
       }
       RTC_CHECK(
           file_.Write(converted_samples.data(),
@@ -264,6 +278,7 @@ void WavWriter::WriteSamples(const float* samples, siz
       RTC_CHECK_EQ(format_, WavFormat::kWavFormatIeeeFloat);
       std::array<float, kMaxChunksize> converted_samples;
       for (size_t j = 0; j < num_samples_to_write; ++j) {
+        // TODO: is swap needed for big-endian here?
         converted_samples[j] = FloatS16ToFloat(samples[i + j]);
       }
       RTC_CHECK(
