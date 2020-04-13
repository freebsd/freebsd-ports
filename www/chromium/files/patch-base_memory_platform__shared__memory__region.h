--- base/memory/platform_shared_memory_region.h.orig	2020-02-03 21:52:37 UTC
+++ base/memory/platform_shared_memory_region.h
@@ -27,7 +27,7 @@
 #include "base/files/scoped_file.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 namespace content {
 class SandboxIPCHandler;
 }
@@ -121,7 +121,7 @@ class BASE_EXPORT PlatformSharedMemoryRegion {
     kMaxValue = GET_SHMEM_TEMP_DIR_FAILURE
   };
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Structure to limit access to executable region creation.
   struct ExecutableRegion {
    private:
@@ -266,7 +266,7 @@ class BASE_EXPORT PlatformSharedMemoryRegion {
                            CheckPlatformHandlePermissionsCorrespondToMode);
   static PlatformSharedMemoryRegion Create(Mode mode,
                                            size_t size
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
                                            ,
                                            bool executable = false
 #endif
