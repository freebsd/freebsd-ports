--- base/memory/platform_shared_memory_region.h.orig	2025-10-21 16:57:35 UTC
+++ base/memory/platform_shared_memory_region.h
@@ -99,7 +99,7 @@ class BASE_EXPORT PlatformSharedMemoryRegion {
 #if BUILDFLAG(IS_FUCHSIA)
     kNotVmo,
 #endif
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     kFcntlFailed,
     kReadOnlyFdNotReadOnly,
     kUnexpectedReadOnlyFd,
@@ -230,7 +230,7 @@ class BASE_EXPORT PlatformSharedMemoryRegion {
                            CheckPlatformHandlePermissionsCorrespondToMode);
   static PlatformSharedMemoryRegion Create(Mode mode,
                                            size_t size
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
                                            ,
                                            bool executable = false
 #endif
