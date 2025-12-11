--- third_party/perfetto/include/perfetto/ext/base/thread_utils.h.orig	2025-12-10 15:04:57 UTC
+++ third_party/perfetto/include/perfetto/ext/base/thread_utils.h
@@ -41,9 +41,10 @@
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
