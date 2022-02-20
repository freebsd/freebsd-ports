--- base/memory/platform_shared_memory_region_posix.cc.orig	2022-02-07 13:39:41 UTC
+++ base/memory/platform_shared_memory_region_posix.cc
@@ -70,7 +70,7 @@ FDPair ScopedFDPair::get() const {
   return {fd.get(), readonly_fd.get()};
 }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // static
 ScopedFD PlatformSharedMemoryRegion::ExecutableRegion::CreateFD(size_t size) {
   PlatformSharedMemoryRegion region =
@@ -204,7 +204,7 @@ bool PlatformSharedMemoryRegion::MapAtInternal(off_t o
 // static
 PlatformSharedMemoryRegion PlatformSharedMemoryRegion::Create(Mode mode,
                                                               size_t size
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
                                                               ,
                                                               bool executable
 #endif
@@ -233,7 +233,7 @@ PlatformSharedMemoryRegion PlatformSharedMemoryRegion:
   // flag.
   FilePath directory;
   if (!GetShmemTempDir(
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
           executable,
 #else
           false /* executable */,
