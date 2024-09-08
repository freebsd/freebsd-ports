--- third_party/perfetto/src/base/utils.cc.orig	2024-08-26 14:40:28 UTC
+++ third_party/perfetto/src/base/utils.cc
@@ -38,8 +38,9 @@
 #include <mach/vm_page_size.h>
 #endif
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)
 #include <linux/prctl.h>
 #include <sys/prctl.h>
 
@@ -338,8 +339,9 @@ void AlignedFree(void* ptr) {
 }
 
 bool IsSyncMemoryTaggingEnabled() {
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)
   // Compute only once per lifetime of the process.
   static bool cached_value = [] {
     const int res = prctl(PR_GET_TAGGED_ADDR_CTRL, 0, 0, 0, 0);
