--- ui/gl/sync_control_vsync_provider.cc.orig	2017-12-15 02:04:52.000000000 +0100
+++ ui/gl/sync_control_vsync_provider.cc	2017-12-24 20:23:51.378230000 +0100
@@ -11,7 +11,7 @@
 #include "base/trace_event/trace_event.h"
 #include "build/build_config.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // These constants define a reasonable range for a calculated refresh interval.
 // Calculating refreshes out of this range will be considered a fatal error.
 const int64_t kMinVsyncIntervalUs = base::Time::kMicrosecondsPerSecond / 400;
@@ -26,7 +26,7 @@
 namespace gl {
 
 SyncControlVSyncProvider::SyncControlVSyncProvider() : gfx::VSyncProvider() {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // On platforms where we can't get an accurate reading on the refresh
   // rate we fall back to the assumption that we're displaying 60 frames
   // per second.
@@ -39,7 +39,7 @@
 void SyncControlVSyncProvider::GetVSyncParameters(
     const UpdateVSyncCallback& callback) {
   TRACE_EVENT0("gpu", "SyncControlVSyncProvider::GetVSyncParameters");
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // The actual clock used for the system time returned by glXGetSyncValuesOML
   // is unspecified. In practice, the clock used is likely to be either
   // CLOCK_REALTIME or CLOCK_MONOTONIC, so we compare the returned time to the
@@ -155,7 +155,7 @@
   last_timebase_ = timebase;
   last_media_stream_counter_ = media_stream_counter;
   callback.Run(timebase, last_good_interval_);
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 }
 
 }  // namespace gl
