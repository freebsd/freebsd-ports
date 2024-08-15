--- third_party/perfetto/src/tracing/track.cc.orig	2024-07-31 14:19:23 UTC
+++ third_party/perfetto/src/tracing/track.cc
@@ -155,7 +155,7 @@ namespace internal {
 namespace {
 
 uint64_t GetProcessStartTime() {
-#if !PERFETTO_BUILDFLAG(PERFETTO_OS_WIN)
+#if !PERFETTO_BUILDFLAG(PERFETTO_OS_WIN) && !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)
   std::string stat;
   if (!base::ReadFile("/proc/self/stat", &stat))
     return 0u;
