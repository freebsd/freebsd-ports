--- src/third_party/perfetto/src/base/clock_snapshots.cc.orig	2026-10-18 18:43:23 UTC
+++ src/third_party/perfetto/src/base/clock_snapshots.cc
@@ -27,6 +27,7 @@ ClockSnapshotVector CaptureClockSnapshot
 #if !PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE) &&   \
     !PERFETTO_BUILDFLAG(PERFETTO_OS_WIN) &&     \
     !PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_OPENBSD) && \
     !PERFETTO_BUILDFLAG(PERFETTO_OS_NACL) &&    \
     !PERFETTO_BUILDFLAG(PERFETTO_OS_QNX)
   struct {
