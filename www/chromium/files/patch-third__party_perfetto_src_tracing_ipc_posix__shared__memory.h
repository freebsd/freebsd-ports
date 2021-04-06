--- third_party/perfetto/src/tracing/ipc/posix_shared_memory.h.orig	2021-03-15 13:11:37 UTC
+++ third_party/perfetto/src/tracing/ipc/posix_shared_memory.h
@@ -21,7 +21,8 @@
 
 #if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) ||   \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)
+    PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE) ||   \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
 
 #include <stddef.h>
 
@@ -76,5 +77,5 @@ class PosixSharedMemory : public SharedMemory {
 
 }  // namespace perfetto
 
-#endif  // OS_LINUX || OS_ANDROID || OS_APPLE
+#endif  // OS_LINUX || OS_ANDROID || OS_APPLE || OS_FREEBSD
 #endif  // SRC_TRACING_IPC_POSIX_SHARED_MEMORY_H_
