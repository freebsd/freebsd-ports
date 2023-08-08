--- src/3rdparty/chromium/third_party/perfetto/src/tracing/core/tracing_service_impl.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/third_party/perfetto/src/tracing/core/tracing_service_impl.cc
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
