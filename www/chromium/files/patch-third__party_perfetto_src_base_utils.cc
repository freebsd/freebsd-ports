--- third_party/perfetto/src/base/utils.cc.orig	2021-07-19 18:47:28 UTC
+++ third_party/perfetto/src/base/utils.cc
@@ -22,7 +22,8 @@
 
 #if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) ||   \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)
+    PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE) ||   \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
 #include <unistd.h>  // For getpagesize() and geteuid() & fork()
 #endif
 
@@ -68,8 +69,9 @@ void MaybeReleaseAllocatorMemToOS() {
 
 uint32_t GetSysPageSize() {
   ignore_result(kPageSize);  // Just to keep the amalgamated build happy.
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
+#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) ||   \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) || \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
   static std::atomic<uint32_t> page_size{0};
   // This function might be called in hot paths. Avoid calling getpagesize() all
   // the times, in many implementations getpagesize() calls sysconf() which is
@@ -90,7 +92,8 @@ uint32_t GetSysPageSize() {
 uid_t GetCurrentUserId() {
 #if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) ||   \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)
+    PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE) ||   \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
   return geteuid();
 #else
   // TODO(primiano): On Windows we could hash the current user SID and derive a
