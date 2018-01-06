--- src/3rdparty/chromium/ui/gl/sync_control_vsync_provider.cc.orig	2017-01-26 00:49:32 UTC
+++ src/3rdparty/chromium/ui/gl/sync_control_vsync_provider.cc
@@ -11,7 +11,7 @@
 #include "base/trace_event/trace_event.h"
 #include "build/build_config.h"
 
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_WIN)
 // These constants define a reasonable range for a calculated refresh interval.
 // Calculating refreshes out of this range will be considered a fatal error.
 const int64_t kMinVsyncIntervalUs = base::Time::kMicrosecondsPerSecond / 400;
@@ -21,17 +21,17 @@ const int64_t kMaxVsyncIntervalUs = base
 // we think the latest computed interval is invalid (noisey due to
 // monitor configuration change, moving a window between monitors, etc.).
 const double kRelativeIntervalDifferenceThreshold = 0.05;
-#endif  // defined(OS_LINUX) || defined(OS_WIN)
+#endif  // defined(OS_LINUX) || defined(OS_BSD) || defined(OS_WIN)
 
 namespace gl {
 
 SyncControlVSyncProvider::SyncControlVSyncProvider() : gfx::VSyncProvider() {
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_WIN)
   // On platforms where we can't get an accurate reading on the refresh
   // rate we fall back to the assumption that we're displaying 60 frames
   // per second.
   last_good_interval_ = base::TimeDelta::FromSeconds(1) / 60;
-#endif  // defined(OS_LINUX) || defined(OS_WIN)
+#endif  // defined(OS_LINUX) || defined(OS_BSD) || defined(OS_WIN)
 }
 
 SyncControlVSyncProvider::~SyncControlVSyncProvider() {}
@@ -39,7 +39,7 @@ SyncControlVSyncProvider::~SyncControlVS
 void SyncControlVSyncProvider::GetVSyncParameters(
     const UpdateVSyncCallback& callback) {
   TRACE_EVENT0("gpu", "SyncControlVSyncProvider::GetVSyncParameters");
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_WIN)
   base::TimeTicks timebase;
 
   int64_t system_time;
@@ -129,10 +129,10 @@ void SyncControlVSyncProvider::GetVSyncP
   last_timebase_ = timebase;
   last_media_stream_counter_ = media_stream_counter;
   callback.Run(timebase, last_good_interval_);
-#endif  // defined(OS_LINUX) || defined(OS_WIN)
+#endif  // defined(OS_LINUX) || defined(OS_BSD) || defined(OS_WIN)
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 bool SyncControlVSyncProvider::AdjustSyncValues(int64_t* system_time,
                                                 int64_t* media_stream_counter) {
   // Both Intel and Mali drivers will return TRUE for GetSyncValues
@@ -192,7 +192,7 @@ bool SyncControlVSyncProvider::AdjustSyn
 
   return true;
 }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_WIN)
 bool SyncControlVSyncProvider::AdjustSyncValues(int64_t* system_time,
