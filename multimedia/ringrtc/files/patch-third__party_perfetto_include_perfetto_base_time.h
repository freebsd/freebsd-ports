--- src/webrtc/src/third_party/perfetto/include/perfetto/base/time.h.orig	2024-05-21 18:07:39 UTC
+++ src/webrtc/src/third_party/perfetto/include/perfetto/base/time.h
@@ -242,7 +242,7 @@ inline TimeNanos GetWallTimeNs() {
 }
 
 inline TimeNanos GetWallTimeRawNs() {
-#if (PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD))
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD) || PERFETTO_BUILDFLAG(PERFETTO_OS_OPENBSD))
   // Note: CLOCK_MONOTONIC_RAW is a Linux extension.
   // FreeBSD doesn't implement it and its CLOCK_MONOTONIC_FAST
   // doesnt implement the same semantics as CLOCK_MONOTONIC_RAW.
