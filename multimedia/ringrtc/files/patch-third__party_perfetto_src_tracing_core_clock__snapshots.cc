--- src/webrtc/src/third_party/perfetto/src/tracing/core/clock_snapshots.cc.orig	2024-04-19 13:02:56 UTC
+++ src/webrtc/src/third_party/perfetto/src/tracing/core/clock_snapshots.cc
@@ -26,7 +26,8 @@ ClockSnapshotVector CaptureClockSnapshots() {
   ClockSnapshotVector snapshot_data;
 #if !PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE) && \
     !PERFETTO_BUILDFLAG(PERFETTO_OS_WIN) &&   \
-    !PERFETTO_BUILDFLAG(PERFETTO_OS_NACL)
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_NACL) &&  \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)
   struct {
     clockid_t id;
     protos::pbzero::BuiltinClock type;
