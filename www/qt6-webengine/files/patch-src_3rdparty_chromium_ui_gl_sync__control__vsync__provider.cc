--- src/3rdparty/chromium/ui/gl/sync_control_vsync_provider.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/ui/gl/sync_control_vsync_provider.cc
@@ -11,7 +11,7 @@
 #include "base/trace_event/trace_event.h"
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // These constants define a reasonable range for a calculated refresh interval.
 // Calculating refreshes out of this range will be considered a fatal error.
 const int64_t kMinVsyncIntervalUs = base::Time::kMicrosecondsPerSecond / 400;
@@ -26,7 +26,7 @@ SyncControlVSyncProvider::SyncControlVSyncProvider() :
 namespace gl {
 
 SyncControlVSyncProvider::SyncControlVSyncProvider() : gfx::VSyncProvider() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // On platforms where we can't get an accurate reading on the refresh
   // rate we fall back to the assumption that we're displaying 60 frames
   // per second.
@@ -48,7 +48,7 @@ bool SyncControlVSyncProvider::GetVSyncParametersIfAva
     base::TimeTicks* timebase_out,
     base::TimeDelta* interval_out) {
   TRACE_EVENT0("gpu", "SyncControlVSyncProvider::GetVSyncParameters");
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // The actual clock used for the system time returned by glXGetSyncValuesOML
   // is unspecified. In practice, the clock used is likely to be either
   // CLOCK_REALTIME or CLOCK_MONOTONIC, so we compare the returned time to the
@@ -159,7 +159,7 @@ bool SyncControlVSyncProvider::SupportGetVSyncParamete
 }
 
 bool SyncControlVSyncProvider::SupportGetVSyncParametersIfAvailable() const {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
