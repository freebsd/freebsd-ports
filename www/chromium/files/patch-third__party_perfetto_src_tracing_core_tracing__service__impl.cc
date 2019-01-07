--- third_party/perfetto/src/tracing/core/tracing_service_impl.cc.orig	2018-12-15 19:14:38.117664000 +0100
+++ third_party/perfetto/src/tracing/core/tracing_service_impl.cc	2018-12-15 19:15:20.324077000 +0100
@@ -1231,7 +1231,8 @@
   protos::ClockSnapshot* clock_snapshot = packet.mutable_clock_snapshot();
 
 #if !PERFETTO_BUILDFLAG(PERFETTO_OS_MACOSX) && \
-    !PERFETTO_BUILDFLAG(PERFETTO_OS_WIN)
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_WIN) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
   struct {
     clockid_t id;
     protos::ClockSnapshot::Clock::Type type;
