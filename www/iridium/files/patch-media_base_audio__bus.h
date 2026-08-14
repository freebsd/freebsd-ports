--- media/base/audio_bus.h.orig	2026-08-13 16:48:13 UTC
+++ media/base/audio_bus.h
@@ -110,6 +110,23 @@ class MEDIA_EXPORT AudioBus {
   // Returns the currently used bitstream data.
   BitstreamData bitstream_data() const { return bitstream_data_; }
 
+  // Note: DEPRECATED, prefer spanified version instead.
+  // Overwrites the sample values stored in this AudioBus instance with values
+  // from a given interleaved `source_buffer` with expected layout
+  // [ch0, ch1, ..., chN, ch0, ch1, ...] and sample values in the format
+  // corresponding to the given SourceSampleTypeTraits.
+  // The sample values are converted to float values by means of the method
+  // convert_to_float32() provided by the SourceSampleTypeTraits. For a list of
+  // ready-to-use SampleTypeTraits, see file audio_sample_types.h.
+  // If `num_frames_to_write` is less than frames(), the remaining frames are
+  // zeroed out. If `num_frames_to_write` is more than frames(), this results in
+  // undefined behavior.
+  // TODO(crbug.com/373960632): Delete this function.
+  template <class SourceSampleTypeTraits>
+  void FromInterleaved(
+      const typename SourceSampleTypeTraits::ValueType* source_buffer,
+      int num_frames_to_write);
+
   // Overwrites every sample stored in this AudioBus instance with values
   // from a given interleaved `source` with expected layout
   // [ch0, ch1, ..., chN, ch0, ch1, ...]. The sample values are converted to
@@ -122,13 +139,36 @@ class MEDIA_EXPORT AudioBus {
       base::span<const typename SourceSampleTypeTraits::ValueType> source,
       bool zero_remaining_frames = false);
 
+  // Note: DEPRECATED, prefer spanified version instead.
   // Similar to FromInterleaved...(), but overwrites the frames starting at a
+  // given offset `write_offset_in_frames` and does not zero out frames that are
+  // not overwritten.
+  // TODO(crbug.com/373960632): Delete this function.
+  template <class SourceSampleTypeTraits>
+  void FromInterleavedPartial(
+      const typename SourceSampleTypeTraits::ValueType* source_buffer,
+      int write_offset_in_frames,
+      int num_frames_to_write);
+
+  // Similar to FromInterleaved...(), but overwrites the frames starting at a
   // given offset `write_offset`, without zero'ing other frames.
   template <class SourceSampleTypeTraits>
   void FromInterleavedPartial(
       base::span<const typename SourceSampleTypeTraits::ValueType> source,
       size_t write_offset);
 
+  // Note: DEPRECATED, prefer spanified version instead.
+  // Reads the sample values stored in this AudioBus instance and places them
+  // into the given `dest_buffer` in interleaved format using the sample format
+  // specified by TargetSampleTypeTraits. For a list of ready-to-use
+  // SampleTypeTraits, see file audio_sample_types.h. If `num_frames_to_read` is
+  // larger than frames(), this results in undefined behavior.
+  // TODO(crbug.com/373960632): Delete this function.
+  template <class TargetSampleTypeTraits>
+  void ToInterleaved(
+      int num_frames_to_read,
+      typename TargetSampleTypeTraits::ValueType* dest_buffer) const;
+
   // Fills `dest` with the sample values in this AudioBus instance. Converts the
   // samples to the format specified by `TargetSampleTypeTraits` and places them
   // in interleaved format.
@@ -138,6 +178,16 @@ class MEDIA_EXPORT AudioBus {
   void ToInterleaved(
       base::span<typename TargetSampleTypeTraits::ValueType> dest) const;
 
+  // Note: DEPRECATED, prefer spanified version instead.
+  // Similar to ToInterleaved(), but reads the frames starting at a given
+  // offset `read_offset_in_frames`.
+  // TODO(crbug.com/373960632): Delete this function.
+  template <class TargetSampleTypeTraits>
+  void ToInterleavedPartial(
+      int read_offset_in_frames,
+      int num_frames_to_read,
+      typename TargetSampleTypeTraits::ValueType* dest_buffer) const;
+
   // Similar to ToInterleaved...(), but reads the frames starting at a given
   // `read_offset`.
   // Note: `dest` must have a multiple of `channels()` elements, but it does not
@@ -243,6 +293,12 @@ class MEDIA_EXPORT AudioBus {
 
   template <class SourceSampleTypeTraits>
   static void CopyConvertFromInterleavedSourceToAudioBus(
+      const typename SourceSampleTypeTraits::ValueType* source_buffer,
+      int write_offset_in_frames,
+      int num_frames_to_write,
+      AudioBus* dest);
+  template <class SourceSampleTypeTraits>
+  static void CopyConvertFromInterleavedSourceToAudioBus(
       base::span<const typename SourceSampleTypeTraits::ValueType> source,
       size_t write_offset,
       AudioBus* dest);
@@ -250,6 +306,12 @@ class MEDIA_EXPORT AudioBus {
   template <class TargetSampleTypeTraits>
   static void CopyConvertFromAudioBusToInterleavedTarget(
       const AudioBus* source,
+      int read_offset_in_frames,
+      int num_frames_to_read,
+      typename TargetSampleTypeTraits::ValueType* dest_buffer);
+  template <class TargetSampleTypeTraits>
+  static void CopyConvertFromAudioBusToInterleavedTarget(
+      const AudioBus* source,
       size_t read_offset,
       base::span<typename TargetSampleTypeTraits::ValueType> dest);
 
@@ -298,6 +360,17 @@ class MEDIA_EXPORT AudioBus {
 // Delegates to FromInterleavedPartial()
 template <class SourceSampleTypeTraits>
 void AudioBus::FromInterleaved(
+    const typename SourceSampleTypeTraits::ValueType* source_buffer,
+    int num_frames_to_write) {
+  FromInterleavedPartial<SourceSampleTypeTraits>(source_buffer, 0,
+                                                 num_frames_to_write);
+  // Zero any remaining frames.
+  ZeroFramesPartial(num_frames_to_write, frames_ - num_frames_to_write);
+}
+
+// Delegates to FromInterleavedPartial()
+template <class SourceSampleTypeTraits>
+void AudioBus::FromInterleaved(
     base::span<const typename SourceSampleTypeTraits::ValueType> source,
     bool zero_remaining_frames) {
   const size_t source_frame_count = get_frame_count(source, channels());
@@ -318,6 +391,16 @@ void AudioBus::FromInterleaved(
 
 template <class SourceSampleTypeTraits>
 void AudioBus::FromInterleavedPartial(
+    const typename SourceSampleTypeTraits::ValueType* source_buffer,
+    int write_offset_in_frames,
+    int num_frames_to_write) {
+  CheckOverflow(write_offset_in_frames, num_frames_to_write, frames_);
+  CopyConvertFromInterleavedSourceToAudioBus<SourceSampleTypeTraits>(
+      source_buffer, write_offset_in_frames, num_frames_to_write, this);
+}
+
+template <class SourceSampleTypeTraits>
+void AudioBus::FromInterleavedPartial(
     base::span<const typename SourceSampleTypeTraits::ValueType> source,
     size_t write_offset) {
   const size_t frame_count = get_frame_count(source, channels());
@@ -332,6 +415,15 @@ void AudioBus::FromInterleavedPartial(
 // Delegates to ToInterleavedPartial()
 template <class TargetSampleTypeTraits>
 void AudioBus::ToInterleaved(
+    int num_frames_to_read,
+    typename TargetSampleTypeTraits::ValueType* dest_buffer) const {
+  ToInterleavedPartial<TargetSampleTypeTraits>(0, num_frames_to_read,
+                                               dest_buffer);
+}
+
+// Delegates to ToInterleavedPartial()
+template <class TargetSampleTypeTraits>
+void AudioBus::ToInterleaved(
     base::span<typename TargetSampleTypeTraits::ValueType> dest) const {
   const size_t frames_count = get_frame_count(dest, channels());
   CHECK_EQ(frames_count, frames_);
@@ -340,6 +432,16 @@ void AudioBus::ToInterleaved(
 
 template <class TargetSampleTypeTraits>
 void AudioBus::ToInterleavedPartial(
+    int read_offset_in_frames,
+    int num_frames_to_read,
+    typename TargetSampleTypeTraits::ValueType* dest) const {
+  CheckOverflow(read_offset_in_frames, num_frames_to_read, frames_);
+  CopyConvertFromAudioBusToInterleavedTarget<TargetSampleTypeTraits>(
+      this, read_offset_in_frames, num_frames_to_read, dest);
+}
+
+template <class TargetSampleTypeTraits>
+void AudioBus::ToInterleavedPartial(
     size_t read_offset,
     base::span<typename TargetSampleTypeTraits::ValueType> dest) const {
   const size_t frame_count = get_frame_count(dest, channels());
@@ -350,8 +452,30 @@ void AudioBus::ToInterleavedPartial(
       this, read_offset, dest);
 }
 
+// TODO(chfremer): Consider using vector instructions to speed this up,
+//                 https://crbug.com/619628
 template <class SourceSampleTypeTraits>
 void AudioBus::CopyConvertFromInterleavedSourceToAudioBus(
+    const typename SourceSampleTypeTraits::ValueType* source_buffer,
+    int write_offset_in_frames,
+    int num_frames_to_write,
+    AudioBus* dest) {
+  const int channels = dest->channels();
+  for (int ch = 0; ch < channels; ++ch) {
+    AudioBus::Channel channel_data = dest->channel(ch);
+    for (int target_frame_index = write_offset_in_frames,
+             read_pos_in_source = ch;
+         target_frame_index < write_offset_in_frames + num_frames_to_write;
+         ++target_frame_index, read_pos_in_source += channels) {
+      auto source_value = UNSAFE_TODO(source_buffer[read_pos_in_source]);
+      channel_data[target_frame_index] =
+          SourceSampleTypeTraits::ToFloat(source_value);
+    }
+  }
+}
+
+template <class SourceSampleTypeTraits>
+void AudioBus::CopyConvertFromInterleavedSourceToAudioBus(
     base::span<const typename SourceSampleTypeTraits::ValueType> source,
     size_t write_offset,
     AudioBus* dest) {
@@ -368,6 +492,27 @@ void AudioBus::CopyConvertFromInterleavedSourceToAudio
          ++dest_idx, src_idx += channels) {
       auto source_sample = source[src_idx];
       channel_data[dest_idx] = SourceSampleTypeTraits::ToFloat(source_sample);
+    }
+  }
+}
+
+// TODO(chfremer): Consider using vector instructions to speed this up,
+//                 https://crbug.com/619628
+template <class TargetSampleTypeTraits>
+void AudioBus::CopyConvertFromAudioBusToInterleavedTarget(
+    const AudioBus* source,
+    int read_offset_in_frames,
+    int num_frames_to_read,
+    typename TargetSampleTypeTraits::ValueType* dest_buffer) {
+  const int channels = source->channels();
+  for (int ch = 0; ch < channels; ++ch) {
+    AudioBus::ConstChannel channel_data = source->channel(ch);
+    for (int source_frame_index = read_offset_in_frames, write_pos_in_dest = ch;
+         source_frame_index < read_offset_in_frames + num_frames_to_read;
+         ++source_frame_index, write_pos_in_dest += channels) {
+      float sourceSampleValue = channel_data[source_frame_index];
+      UNSAFE_TODO(dest_buffer[write_pos_in_dest]) =
+          TargetSampleTypeTraits::FromFloat(sourceSampleValue);
     }
   }
 }
