--- third_party/perfetto/src/tracing/core/service_impl.cc.orig	2018-08-04 21:18:16.978067000 +0200
+++ third_party/perfetto/src/tracing/core/service_impl.cc	2018-08-04 21:18:54.197576000 +0200
@@ -1041,7 +1041,7 @@
   protos::TrustedPacket packet;
   protos::ClockSnapshot* clock_snapshot = packet.mutable_clock_snapshot();
 
-#if !PERFETTO_BUILDFLAG(PERFETTO_OS_MACOSX) && !PERFETTO_BUILDFLAG(PERFETTO_OS_WIN)
+#if !PERFETTO_BUILDFLAG(PERFETTO_OS_MACOSX) && !PERFETTO_BUILDFLAG(PERFETTO_OS_WIN) && !PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
   struct {
     clockid_t id;
     protos::ClockSnapshot::Clock::Type type;
