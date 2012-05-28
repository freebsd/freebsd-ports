--- media/audio/pulse/pulse_output.cc.orig	2012-05-09 09:01:10.000000000 +0200
+++ media/audio/pulse/pulse_output.cc	2012-05-20 11:49:26.000000000 +0200
@@ -8,7 +8,7 @@
 #include "base/message_loop.h"
 #include "media/audio/audio_parameters.h"
 #include "media/audio/audio_util.h"
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 #include "media/audio/linux/audio_manager_linux.h"
 #elif defined(OS_OPENBSD)
 #include "media/audio/openbsd/audio_manager_openbsd.h"
@@ -126,7 +126,7 @@
   PulseAudioOutputStream* stream =
       reinterpret_cast<PulseAudioOutputStream*>(stream_addr);
 
-  DCHECK_EQ(stream->manager_->GetMessageLoop(), MessageLoop::current());
+  DCHECK(stream->manager_->GetMessageLoop()->BelongsToCurrentThread());
 
   stream->write_callback_handled_ = true;
 
@@ -136,16 +136,16 @@
 
 PulseAudioOutputStream::PulseAudioOutputStream(const AudioParameters& params,
                                                AudioManagerPulse* manager)
-    : channel_layout_(params.channel_layout),
+    : channel_layout_(params.channel_layout()),
       channel_count_(ChannelLayoutToChannelCount(channel_layout_)),
-      sample_format_(BitsToPASampleFormat(params.bits_per_sample)),
-      sample_rate_(params.sample_rate),
-      bytes_per_frame_(params.channels * params.bits_per_sample / 8),
+      sample_format_(BitsToPASampleFormat(params.bits_per_sample())),
+      sample_rate_(params.sample_rate()),
+      bytes_per_frame_(params.channels() * params.bits_per_sample() / 8),
       manager_(manager),
       pa_context_(NULL),
       pa_mainloop_(NULL),
       playback_handle_(NULL),
-      packet_size_(params.GetPacketSize()),
+      packet_size_(params.GetBytesPerBuffer()),
       frames_per_packet_(packet_size_ / bytes_per_frame_),
       client_buffer_(NULL),
       volume_(1.0f),
@@ -153,7 +153,7 @@
       write_callback_handled_(false),
       ALLOW_THIS_IN_INITIALIZER_LIST(weak_factory_(this)),
       source_callback_(NULL) {
-  DCHECK_EQ(manager_->GetMessageLoop(), MessageLoop::current());
+  DCHECK(manager_->GetMessageLoop()->BelongsToCurrentThread());
 
   // TODO(slock): Sanity check input values.
 }
@@ -167,7 +167,7 @@
 }
 
 bool PulseAudioOutputStream::Open() {
-  DCHECK_EQ(manager_->GetMessageLoop(), MessageLoop::current());
+  DCHECK(manager_->GetMessageLoop()->BelongsToCurrentThread());
 
   // TODO(slock): Possibly move most of this to an OpenPlaybackDevice function
   // in a new class 'pulse_util', like alsa_util.
@@ -270,7 +270,7 @@
 }
 
 void PulseAudioOutputStream::Close() {
-  DCHECK_EQ(manager_->GetMessageLoop(), MessageLoop::current());
+  DCHECK(manager_->GetMessageLoop()->BelongsToCurrentThread());
 
   Reset();
 
@@ -280,7 +280,7 @@
 }
 
 void PulseAudioOutputStream::WaitForWriteRequest() {
-  DCHECK_EQ(manager_->GetMessageLoop(), MessageLoop::current());
+  DCHECK(manager_->GetMessageLoop()->BelongsToCurrentThread());
 
   if (stream_stopped_)
     return;
@@ -370,7 +370,7 @@
     size_t chunk_size;
 
     // Stop writing if there is no more data available.
-    if (!client_buffer_->GetCurrentChunk(&chunk, &chunk_size))
+    if (!client_buffer_->GetCurrentChunk(&chunk, (int*) &chunk_size))
       break;
 
     // Write data to stream.
@@ -382,7 +382,7 @@
 }
 
 void PulseAudioOutputStream::Start(AudioSourceCallback* callback) {
-  DCHECK_EQ(manager_->GetMessageLoop(), MessageLoop::current());
+  DCHECK(manager_->GetMessageLoop()->BelongsToCurrentThread());
   CHECK(callback);
   DLOG_IF(ERROR, !playback_handle_)
       << "Open() has not been called successfully";
@@ -402,19 +402,19 @@
 }
 
 void PulseAudioOutputStream::Stop() {
-  DCHECK_EQ(manager_->GetMessageLoop(), MessageLoop::current());
+  DCHECK(manager_->GetMessageLoop()->BelongsToCurrentThread());
 
   stream_stopped_ = true;
 }
 
 void PulseAudioOutputStream::SetVolume(double volume) {
-  DCHECK_EQ(manager_->GetMessageLoop(), MessageLoop::current());
+  DCHECK(manager_->GetMessageLoop()->BelongsToCurrentThread());
 
   volume_ = static_cast<float>(volume);
 }
 
 void PulseAudioOutputStream::GetVolume(double* volume) {
-  DCHECK_EQ(manager_->GetMessageLoop(), MessageLoop::current());
+  DCHECK(manager_->GetMessageLoop()->BelongsToCurrentThread());
 
   *volume = volume_;
 }
