--- third_party/perfetto/src/tracing/core/tracing_service_impl.cc.orig	2019-10-21 19:09:15 UTC
+++ third_party/perfetto/src/tracing/core/tracing_service_impl.cc
@@ -2180,7 +2180,8 @@ void TracingServiceImpl::SnapshotClocks(std::vector<Tr
   protos::ClockSnapshot* clock_snapshot = packet.mutable_clock_snapshot();
 
 #if !PERFETTO_BUILDFLAG(PERFETTO_OS_MACOSX) && \
-    !PERFETTO_BUILDFLAG(PERFETTO_OS_WIN)
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_WIN) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
   struct {
     clockid_t id;
     protos::ClockSnapshot::Clock::BuiltinClocks type;
