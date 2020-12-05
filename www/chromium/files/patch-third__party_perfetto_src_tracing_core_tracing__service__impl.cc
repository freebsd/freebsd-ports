--- third_party/perfetto/src/tracing/core/tracing_service_impl.cc.orig	2020-11-13 06:42:22 UTC
+++ third_party/perfetto/src/tracing/core/tracing_service_impl.cc
@@ -2569,8 +2569,9 @@ bool TracingServiceImpl::SnapshotClocks(
 
   TracingSession::ClockSnapshotData new_snapshot_data;
 
-#if !PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE) && \
-    !PERFETTO_BUILDFLAG(PERFETTO_OS_WIN) &&   \
+#if !PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE) &&   \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_WIN) &&     \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD) && \
     !PERFETTO_BUILDFLAG(PERFETTO_OS_NACL)
   struct {
     clockid_t id;
