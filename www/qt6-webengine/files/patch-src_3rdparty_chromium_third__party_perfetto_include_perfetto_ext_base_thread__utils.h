--- src/3rdparty/chromium/third_party/perfetto/include/perfetto/ext/base/thread_utils.h.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/third_party/perfetto/include/perfetto/ext/base/thread_utils.h
@@ -40,9 +40,10 @@ namespace base {
 namespace perfetto {
 namespace base {
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) ||   \
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) ||   \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)
+    PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)
 // Sets the "comm" of the calling thread to the first 15 chars of the given
 // string.
 inline bool MaybeSetThreadName(const std::string& name) {
