--- src/3rdparty/chromium/third_party/perfetto/src/base/clock_snapshots.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/third_party/perfetto/src/base/clock_snapshots.cc
@@ -27,6 +27,7 @@ ClockSnapshotVector CaptureClockSnapshots() {
 #if !PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE) && \
     !PERFETTO_BUILDFLAG(PERFETTO_OS_WIN) &&   \
     !PERFETTO_BUILDFLAG(PERFETTO_OS_NACL) &&  \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD) &&  \
     !PERFETTO_BUILDFLAG(PERFETTO_OS_QNX)
   struct {
     clockid_t id;
