--- chromecast/media/cma/backend/media_pipeline_backend_for_mixer.cc.orig	2019-06-04 18:55:21 UTC
+++ chromecast/media/cma/backend/media_pipeline_backend_for_mixer.cc
@@ -16,9 +16,9 @@
 #include "chromecast/media/cma/backend/av_sync.h"
 #include "chromecast/media/cma/backend/video_decoder_for_mixer.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "chromecast/media/cma/backend/audio_buildflags.h"
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_FUCHSIA)
 #include <zircon/syscalls.h>
@@ -239,7 +239,7 @@ MediaPipelineBackendForMixer::GetTaskRunner() const {
   return static_cast<TaskRunnerImpl*>(params_.task_runner)->runner();
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 int64_t MediaPipelineBackendForMixer::MonotonicClockNow() const {
   timespec now = {0, 0};
 #if BUILDFLAG(MEDIA_CLOCK_MONOTONIC_RAW)
