--- ui/gl/sync_control_vsync_provider.cc.orig	2015-04-14 18:19:00.000000000 -0400
+++ ui/gl/sync_control_vsync_provider.cc	2015-04-28 08:42:41.263448000 -0400
@@ -9,7 +9,7 @@
 #include "base/logging.h"
 #include "base/time/time.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // These constants define a reasonable range for a calculated refresh interval.
 // Calculating refreshes out of this range will be considered a fatal error.
 const int64 kMinVsyncIntervalUs = base::Time::kMicrosecondsPerSecond / 400;
@@ -35,7 +35,7 @@
 
 void SyncControlVSyncProvider::GetVSyncParameters(
     const UpdateVSyncCallback& callback) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   base::TimeTicks timebase;
 
   // The actual clock used for the system time returned by glXGetSyncValuesOML
@@ -151,7 +151,7 @@
   last_timebase_ = timebase;
   last_media_stream_counter_ = media_stream_counter;
   callback.Run(timebase, last_good_interval_);
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 }
 
 }  // namespace gfx
