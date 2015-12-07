--- ui/gl/sync_control_vsync_provider.cc.orig	2015-10-06 22:42:29.000000000 -0400
+++ ui/gl/sync_control_vsync_provider.cc	2015-10-14 12:13:21.879502000 -0400
@@ -10,7 +10,7 @@
 #include "base/time/time.h"
 #include "base/trace_event/trace_event.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // These constants define a reasonable range for a calculated refresh interval.
 // Calculating refreshes out of this range will be considered a fatal error.
 const int64 kMinVsyncIntervalUs = base::Time::kMicrosecondsPerSecond / 400;
@@ -37,7 +37,7 @@
 void SyncControlVSyncProvider::GetVSyncParameters(
     const UpdateVSyncCallback& callback) {
   TRACE_EVENT0("gpu", "SyncControlVSyncProvider::GetVSyncParameters");
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   base::TimeTicks timebase;
 
   // The actual clock used for the system time returned by glXGetSyncValuesOML
@@ -153,7 +153,7 @@
   last_timebase_ = timebase;
   last_media_stream_counter_ = media_stream_counter;
   callback.Run(timebase, last_good_interval_);
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 }
 
 }  // namespace gfx
