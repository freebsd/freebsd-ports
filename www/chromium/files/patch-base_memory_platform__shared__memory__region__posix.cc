--- base/memory/platform_shared_memory_region_posix.cc.orig	2021-04-14 18:40:48 UTC
+++ base/memory/platform_shared_memory_region_posix.cc
@@ -23,7 +23,11 @@ struct ScopedPathUnlinkerTraits {
   static const FilePath* InvalidValue() { return nullptr; }
 
   static void Free(const FilePath* path) {
+#if defined(OS_BSD)
+    if (shm_unlink(path->value().c_str()))
+#else
     if (unlink(path->value().c_str()))
+#endif
       PLOG(WARNING) << "unlink";
   }
 };
@@ -70,7 +74,7 @@ FDPair ScopedFDPair::get() const {
   return {fd.get(), readonly_fd.get()};
 }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // static
 ScopedFD PlatformSharedMemoryRegion::ExecutableRegion::CreateFD(size_t size) {
   PlatformSharedMemoryRegion region =
@@ -79,7 +83,7 @@ ScopedFD PlatformSharedMemoryRegion::ExecutableRegion:
     return region.PassPlatformHandle().fd;
   return ScopedFD();
 }
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 // static
 PlatformSharedMemoryRegion PlatformSharedMemoryRegion::Take(
@@ -204,7 +208,7 @@ bool PlatformSharedMemoryRegion::MapAtInternal(off_t o
 // static
 PlatformSharedMemoryRegion PlatformSharedMemoryRegion::Create(Mode mode,
                                                               size_t size
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
                                                               ,
                                                               bool executable
 #endif
@@ -242,6 +246,22 @@ PlatformSharedMemoryRegion PlatformSharedMemoryRegion:
     return {};
   }
 
+#if defined(OS_BSD)
+  UnguessableToken token = UnguessableToken::Create();
+  FilePath path = directory.Append(token.ToString());
+  ScopedFD fd{HANDLE_EINTR(shm_open(path.value().c_str(), O_CREAT | O_RDWR, 0700))};
+  File shm_file(fd.release());
+
+  if (!shm_file.IsValid()) {
+    PLOG(ERROR) << "Creating shared memory failed";
+    return {};
+  }
+
+  if (HANDLE_EINTR(ftruncate(shm_file.GetPlatformFile(), size)) == -1) {
+    PLOG(ERROR) << "Failed to extend shared memory object to size " << size;
+    return {};
+  }
+#else
   FilePath path;
   ScopedFD fd = CreateAndOpenFdForTemporaryFileInDir(directory, &path);
   File shm_file(fd.release());
@@ -258,6 +278,7 @@ PlatformSharedMemoryRegion PlatformSharedMemoryRegion:
     }
     return {};
   }
+#endif // OS_BSD
 
   // Deleting the file prevents anyone else from mapping it in (making it
   // private), and prevents the need for cleanup (once the last fd is
@@ -267,7 +288,11 @@ PlatformSharedMemoryRegion PlatformSharedMemoryRegion:
   ScopedFD readonly_fd;
   if (mode == Mode::kWritable) {
     // Also open as readonly so that we can ConvertToReadOnly().
+#if defined(OS_BSD)
+    readonly_fd.reset(HANDLE_EINTR(shm_open(path.value().c_str(), O_RDONLY, 0400)));
+#else
     readonly_fd.reset(HANDLE_EINTR(open(path.value().c_str(), O_RDONLY)));
+#endif
     if (!readonly_fd.is_valid()) {
       DPLOG(ERROR) << "open(\"" << path.value() << "\", O_RDONLY) failed";
       return {};
@@ -298,9 +323,15 @@ PlatformSharedMemoryRegion PlatformSharedMemoryRegion:
     }
   }
 
+#if defined(OS_BSD)
   return PlatformSharedMemoryRegion(
       {ScopedFD(shm_file.TakePlatformFile()), std::move(readonly_fd)}, mode,
+      size, token);
+#else
+  return PlatformSharedMemoryRegion(
+      {ScopedFD(shm_file.TakePlatformFile()), std::move(readonly_fd)}, mode,
       size, UnguessableToken::Create());
+#endif  // OS_BSD
 #endif  // !defined(OS_NACL)
 }
 
