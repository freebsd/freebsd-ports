--- third_party/perfetto/src/tracing/core/tracing_service_impl.cc.orig	2020-03-03 18:55:28 UTC
+++ third_party/perfetto/src/tracing/core/tracing_service_impl.cc
@@ -2193,7 +2193,8 @@ void TracingServiceImpl::SnapshotClocks(std::vector<Tr
   auto* clock_snapshot = packet->set_clock_snapshot();
 
 #if !PERFETTO_BUILDFLAG(PERFETTO_OS_MACOSX) && \
-    !PERFETTO_BUILDFLAG(PERFETTO_OS_WIN)
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_WIN) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
   struct {
     clockid_t id;
     protos::pbzero::ClockSnapshot::Clock::BuiltinClocks type;
