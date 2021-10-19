--- third_party/perfetto/src/base/utils.cc.orig	2021-09-14 01:58:28 UTC
+++ third_party/perfetto/src/base/utils.cc
@@ -25,7 +25,8 @@
 #if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) ||   \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) || \
     PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE) ||   \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_FUCHSIA)
+    PERFETTO_BUILDFLAG(PERFETTO_OS_FUCHSIA) || \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
 #include <limits.h>
 #include <unistd.h>  // For getpagesize() and geteuid() & fork()
 #endif
@@ -78,8 +79,9 @@ void MaybeReleaseAllocatorMemToOS() {
 
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
@@ -100,7 +102,8 @@ uint32_t GetSysPageSize() {
 uid_t GetCurrentUserId() {
 #if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) ||   \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)
+    PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE) ||   \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
   return geteuid();
 #else
   // TODO(primiano): On Windows we could hash the current user SID and derive a
@@ -122,7 +125,8 @@ void SetEnv(const std::string& key, const std::string&
 void Daemonize() {
 #if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) ||   \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)
+    PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE) ||   \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
   pid_t pid;
   switch (pid = fork()) {
     case -1:
