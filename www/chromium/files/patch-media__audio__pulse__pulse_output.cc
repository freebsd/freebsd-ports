--- media/audio/pulse/pulse_output.cc.orig	2012-02-05 15:13:12.000000000 +0200
+++ media/audio/pulse/pulse_output.cc	2012-02-05 15:13:41.000000000 +0200
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
