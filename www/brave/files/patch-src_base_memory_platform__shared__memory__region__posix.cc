--- src/base/memory/platform_shared_memory_region_posix.cc.orig	2026-09-25 15:26:43 UTC
+++ src/base/memory/platform_shared_memory_region_posix.cc
@@ -12,6 +12,14 @@
 #include <atomic>
 #include <optional>
 
+#if BUILDFLAG(IS_FREEBSD)
+#include <sys/stat.h>
+#include <unistd.h>
+
+#include <atomic>
+#include <string>
+#endif
+
 #include "base/check_op.h"
 #include "base/files/file.h"
 #include "base/files/file_util.h"
@@ -148,6 +156,84 @@
 
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
+#if BUILDFLAG(IS_FREEBSD)
+// FreeBSD has no /dev/shm, so GetShmemTempDir() hands out $TMPDIR or /tmp,
+// which usually sits on the root file system, ZFS or UFS.  A region created
+// there is an unlinked file on disk: each one costs several file system
+// transactions that queue up behind anything else writing to the same disk (a
+// download, for instance) and its dirty pages are written back for nothing.
+// Regions are created on the UI and IO threads of the browser too -- the
+// discardable memory renderers decode images into is handed out on the IO
+// thread -- so the whole browser stalls whenever the disk is busy.
+//
+// POSIX shared memory objects live in memory and swap, like /dev/shm on Linux.
+// A named object is used rather than SHM_ANON so that a second, read-only
+// descriptor can be opened for it, just like for the file.
+std::atomic_bool g_shm_objects_unusable = false;
+
+// Returns false if no object could be made, the caller then falls back to a
+// file.  Failures that would repeat for every region turn this off for good.
+bool CreateShmObject(size_t size,
+                     bool with_readonly_fd,
+                     ScopedFD* fd,
+                     ScopedFD* readonly_fd) {
+  if (g_shm_objects_unusable.load(std::memory_order_relaxed)) {
+    return false;
+  }
+
+  const std::string name =
+      "/org.chromium.shmem." + UnguessableToken::Create().ToString();
+  ScopedFD rw_fd(HANDLE_EINTR(
+      shm_open(name.c_str(), O_RDWR | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR)));
+  if (!rw_fd.is_valid()) {
+    PLOG(ERROR) << "shm_open(" << name << "), using temporary files";
+    g_shm_objects_unusable.store(true, std::memory_order_relaxed);
+    return false;
+  }
+
+  ScopedFD ro_fd;
+  if (with_readonly_fd) {
+    ro_fd.reset(HANDLE_EINTR(shm_open(name.c_str(), O_RDONLY, 0)));
+  }
+
+  // Nothing else can open the object once the name is gone, and it is freed
+  // together with the last descriptor and mapping.
+  if (shm_unlink(name.c_str()) != 0) {
+    PLOG(ERROR) << "shm_unlink(" << name << "), using temporary files";
+    g_shm_objects_unusable.store(true, std::memory_order_relaxed);
+    return false;
+  }
+
+  if (with_readonly_fd && !ro_fd.is_valid()) {
+    DPLOG(ERROR) << "shm_open(" << name << ", O_RDONLY) failed";
+    return false;
+  }
+
+  if (HANDLE_EINTR(ftruncate(rw_fd.get(), static_cast<off_t>(size))) != 0) {
+    DPLOG(ERROR) << "ftruncate(" << name << ") failed";
+    return false;
+  }
+
+  if (ro_fd.is_valid()) {
+    stat_wrapper_t rw_stat;
+    stat_wrapper_t ro_stat;
+    if (File::Fstat(rw_fd.get(), &rw_stat) != 0 ||
+        File::Fstat(ro_fd.get(), &ro_stat) != 0) {
+      DPLOG(ERROR) << "fstat(" << name << ") failed";
+      return false;
+    }
+    if (rw_stat.st_dev != ro_stat.st_dev || rw_stat.st_ino != ro_stat.st_ino) {
+      LOG(ERROR) << "Writable and read-only shm objects don't match";
+      return false;
+    }
+  }
+
+  *fd = std::move(rw_fd);
+  *readonly_fd = std::move(ro_fd);
+  return true;
+}
+#endif  // BUILDFLAG(IS_FREEBSD)
+
 }  // namespace
 
 // static
@@ -263,7 +349,7 @@
 // static
 PlatformSharedMemoryRegion PlatformSharedMemoryRegion::Create(Mode mode,
                                                               size_t size
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
                                                               ,
                                                               bool executable
 #endif
@@ -295,11 +381,25 @@
   // and be deleted before they ever make it out to disk.
   ScopedAllowBlocking scoped_allow_blocking;
 
+#if BUILDFLAG(IS_FREEBSD)
+  // Executable regions keep going through a file, as they always did.
+  if (!executable) {
+    ScopedFD shm_fd;
+    ScopedFD shm_readonly_fd;
+    if (CreateShmObject(size, mode == Mode::kWritable, &shm_fd,
+                        &shm_readonly_fd)) {
+      return PlatformSharedMemoryRegion(
+          {std::move(shm_fd), std::move(shm_readonly_fd)}, mode, size,
+          UnguessableToken::Create());
+    }
+  }
+#endif
+
   // We don't use shm_open() API in order to support the --disable-dev-shm-usage
   // flag.
   FilePath directory;
   if (!GetShmemTempDir(
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
           executable,
 #else
           false /* executable */,
