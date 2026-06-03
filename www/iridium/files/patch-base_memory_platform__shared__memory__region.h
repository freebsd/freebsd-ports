--- base/memory/platform_shared_memory_region.h.orig	2026-04-15 12:07:04 UTC
+++ base/memory/platform_shared_memory_region.h
@@ -104,7 +104,7 @@ class BASE_EXPORT PlatformSharedMemoryRegion {
 #if BUILDFLAG(IS_FUCHSIA)
     kNotVmo,
 #endif
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     kFcntlFailed,
     kReadOnlyFdNotReadOnly,
     kUnexpectedReadOnlyFd,
@@ -249,7 +249,7 @@ class BASE_EXPORT PlatformSharedMemoryRegion {
                            CheckPlatformHandlePermissionsCorrespondToMode);
   static PlatformSharedMemoryRegion Create(Mode mode,
                                            size_t size
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
                                            ,
                                            bool executable = false
 #endif
