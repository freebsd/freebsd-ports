--- third_party/perfetto/src/base/clock_snapshots.cc.orig	2026-01-14 08:33:23 UTC
+++ third_party/perfetto/src/base/clock_snapshots.cc
@@ -27,6 +27,7 @@ ClockSnapshotVector CaptureClockSnapshots() {
 #if !PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE) &&   \
     !PERFETTO_BUILDFLAG(PERFETTO_OS_WIN) &&     \
     !PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_OPENBSD) && \
     !PERFETTO_BUILDFLAG(PERFETTO_OS_NACL) &&    \
     !PERFETTO_BUILDFLAG(PERFETTO_OS_QNX)
   struct {
