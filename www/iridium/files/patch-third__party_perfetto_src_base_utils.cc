--- third_party/perfetto/src/base/utils.cc.orig	2024-12-22 12:24:29 UTC
+++ third_party/perfetto/src/base/utils.cc
@@ -38,8 +38,9 @@
 #include <mach/vm_page_size.h>
 #endif
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
+     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)
 #include <sys/prctl.h>
 
 #ifndef PR_GET_TAGGED_ADDR_CTRL
@@ -278,14 +279,22 @@ void Daemonize(std::function<int()> parent_cb) {
 
 std::string GetCurExecutablePath() {
   std::string self_path;
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) ||   \
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) ||   \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_FUCHSIA)
+    PERFETTO_BUILDFLAG(PERFETTO_OS_FUCHSIA)) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)
   char buf[PATH_MAX];
   ssize_t size = readlink("/proc/self/exe", buf, sizeof(buf));
   PERFETTO_CHECK(size != -1);
   // readlink does not null terminate.
   self_path = std::string(buf, static_cast<size_t>(size));
+#elif PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)
+  char *buf;
+  const char *cpath = "/usr/local/chrome/chrome";
+  if ((buf = getenv("CHROME_EXE_PATH")) != NULL)
+    self_path = std::string(buf);
+  else
+    self_path = std::string(cpath);
 #elif PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)
   uint32_t size = 0;
   PERFETTO_CHECK(_NSGetExecutablePath(nullptr, &size));
@@ -337,8 +346,9 @@ void AlignedFree(void* ptr) {
 }
 
 bool IsSyncMemoryTaggingEnabled() {
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
+     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)
   // Compute only once per lifetime of the process.
   static bool cached_value = [] {
     const int res = prctl(PR_GET_TAGGED_ADDR_CTRL, 0, 0, 0, 0);
