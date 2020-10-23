--- third_party/perfetto/src/tracing/core/tracing_service_impl.cc.orig	2020-09-08 19:20:01 UTC
+++ third_party/perfetto/src/tracing/core/tracing_service_impl.cc
@@ -2458,6 +2458,7 @@ void TracingServiceImpl::SnapshotClocks(
 
 #if !PERFETTO_BUILDFLAG(PERFETTO_OS_MACOSX) && \
     !PERFETTO_BUILDFLAG(PERFETTO_OS_WIN) &&    \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD) && \
     !PERFETTO_BUILDFLAG(PERFETTO_OS_NACL)
   struct {
     clockid_t id;
