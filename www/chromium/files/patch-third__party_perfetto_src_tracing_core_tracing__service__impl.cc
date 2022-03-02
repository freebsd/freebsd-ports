--- third_party/perfetto/src/tracing/core/tracing_service_impl.cc.orig	2022-02-28 16:54:41 UTC
+++ third_party/perfetto/src/tracing/core/tracing_service_impl.cc
@@ -3008,7 +3008,8 @@ bool TracingServiceImpl::SnapshotClocks(
 
 #if !PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE) && \
     !PERFETTO_BUILDFLAG(PERFETTO_OS_WIN) &&   \
-    !PERFETTO_BUILDFLAG(PERFETTO_OS_NACL)
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_NACL) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)
   struct {
     clockid_t id;
     protos::pbzero::BuiltinClock type;
