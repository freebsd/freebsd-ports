--- src/3rdparty/chromium/third_party/perfetto/src/tracing/core/tracing_service_impl.cc.orig	2019-11-27 21:12:25 UTC
+++ src/3rdparty/chromium/third_party/perfetto/src/tracing/core/tracing_service_impl.cc
@@ -2136,7 +2136,8 @@ void TracingServiceImpl::SnapshotClocks(std::vector<Tr
   protos::ClockSnapshot* clock_snapshot = packet.mutable_clock_snapshot();
 
 #if !PERFETTO_BUILDFLAG(PERFETTO_OS_MACOSX) && \
-    !PERFETTO_BUILDFLAG(PERFETTO_OS_WIN)
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_WIN) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
   struct {
     clockid_t id;
     protos::ClockSnapshot::Clock::Type type;
