--- base/memory/platform_shared_memory_region.h.orig	2021-12-14 11:44:55 UTC
+++ base/memory/platform_shared_memory_region.h
@@ -24,7 +24,7 @@
 #include "base/files/scoped_file.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 namespace content {
 class SandboxIPCHandler;
 }
@@ -117,7 +117,7 @@ class BASE_EXPORT PlatformSharedMemoryRegion {
     kMaxValue = GET_SHMEM_TEMP_DIR_FAILURE
   };
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Structure to limit access to executable region creation.
   struct ExecutableRegion {
    private:
@@ -264,7 +264,7 @@ class BASE_EXPORT PlatformSharedMemoryRegion {
                            CheckPlatformHandlePermissionsCorrespondToMode);
   static PlatformSharedMemoryRegion Create(Mode mode,
                                            size_t size
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
                                            ,
                                            bool executable = false
 #endif
