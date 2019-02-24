--- third_party/perfetto/src/tracing/core/tracing_service_impl.cc.orig	2018-12-12 23:03:02.000000000 +0100
+++ third_party/perfetto/src/tracing/core/tracing_service_impl.cc	2019-01-12 23:04:39.364791000 +0100
@@ -1180,7 +1180,8 @@
 
 void TracingServiceImpl::UpdateMemoryGuardrail() {
 #if !PERFETTO_BUILDFLAG(PERFETTO_CHROMIUM_BUILD) && \
-    !PERFETTO_BUILDFLAG(PERFETTO_OS_MACOSX)
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_MACOSX) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
   uint64_t total_buffer_bytes = 0;
 
   // Sum up all the shared memory buffers.
@@ -1231,7 +1232,8 @@
   protos::ClockSnapshot* clock_snapshot = packet.mutable_clock_snapshot();
 
 #if !PERFETTO_BUILDFLAG(PERFETTO_OS_MACOSX) && \
-    !PERFETTO_BUILDFLAG(PERFETTO_OS_WIN)
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_WIN) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
   struct {
     clockid_t id;
     protos::ClockSnapshot::Clock::Type type;
