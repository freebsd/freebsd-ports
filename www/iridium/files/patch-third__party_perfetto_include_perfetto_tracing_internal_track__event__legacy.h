--- third_party/perfetto/include/perfetto/tracing/internal/track_event_legacy.h.orig	2025-12-10 15:04:57 UTC
+++ third_party/perfetto/include/perfetto/tracing/internal/track_event_legacy.h
@@ -253,7 +253,7 @@ class PERFETTO_EXPORT_COMPONENT LegacyTraceId {
 // are different. E.g. on Mac size_t is considered a different type from
 // uint64_t even though it has the same size and signedness.
 // Below we add overloads for those types that are known to cause ambiguity.
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)
+#if PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE) || defined(__OpenBSD__)
   explicit LegacyTraceId(size_t raw_id) : raw_id_(raw_id) {}
   explicit LegacyTraceId(intptr_t raw_id)
       : raw_id_(static_cast<uint64_t>(raw_id)) {}
