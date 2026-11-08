--- third_party/perfetto/include/perfetto/base/time.h.orig	2026-07-01 06:24:19 UTC
+++ third_party/perfetto/include/perfetto/base/time.h
@@ -294,7 +294,7 @@ inline TimeNanos GetWallTimeNs() {
 }
 
 inline TimeNanos GetWallTimeRawNs() {
-#if (PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD))
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD) || PERFETTO_BUILDFLAG(PERFETTO_OS_OPENBSD))
   // Note: CLOCK_MONOTONIC_RAW is a Linux extension.
   // FreeBSD doesn't implement it and its CLOCK_MONOTONIC_FAST
   // doesnt implement the same semantics as CLOCK_MONOTONIC_RAW.
