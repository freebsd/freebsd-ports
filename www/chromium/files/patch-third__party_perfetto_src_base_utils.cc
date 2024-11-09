--- third_party/perfetto/src/base/utils.cc.orig	2024-10-22 08:31:56 UTC
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
@@ -337,8 +338,9 @@ void AlignedFree(void* ptr) {
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
