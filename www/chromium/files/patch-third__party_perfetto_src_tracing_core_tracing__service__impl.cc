--- third_party/perfetto/src/tracing/core/tracing_service_impl.cc.orig	2023-02-08 09:03:45 UTC
+++ third_party/perfetto/src/tracing/core/tracing_service_impl.cc
@@ -3080,7 +3080,8 @@ bool TracingServiceImpl::SnapshotClocks(
 
 #if !PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE) && \
     !PERFETTO_BUILDFLAG(PERFETTO_OS_WIN) &&   \
-    !PERFETTO_BUILDFLAG(PERFETTO_OS_NACL)
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_NACL) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)
   struct {
     clockid_t id;
     protos::pbzero::BuiltinClock type;
