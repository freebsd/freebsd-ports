--- base/files/file_util_posix.cc.orig	2021-07-19 18:45:05 UTC
+++ base/files/file_util_posix.cc
@@ -23,6 +23,10 @@
 #if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
 #include <sys/sendfile.h>
 #endif
+#if defined(OS_BSD)
+#include <sys/socket.h>
+#include <sys/uio.h>
+#endif
 
 #include "base/base_switches.h"
 #include "base/bits.h"
@@ -383,7 +387,7 @@ bool CreatePipe(ScopedFD* read_fd, ScopedFD* write_fd,
 }
 
 bool CreateLocalNonBlockingPipe(int fds[2]) {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   return pipe2(fds, O_CLOEXEC | O_NONBLOCK) == 0;
 #else
   int raw_fds[2];
@@ -936,8 +940,12 @@ bool AllocateFileRegion(File* file, int64_t offset, si
   // space. It can fail because the filesystem doesn't support it. In that case,
   // use the manual method below.
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
+#if defined(OS_BSD)
+  if (HANDLE_EINTR(posix_fallocate(file->GetPlatformFile(), offset, size)) != -1)
+#else
   if (HANDLE_EINTR(fallocate(file->GetPlatformFile(), 0, offset, size)) != -1)
+#endif
     return true;
   DPLOG(ERROR) << "fallocate";
 #elif defined(OS_APPLE)
@@ -1111,7 +1119,7 @@ int GetMaximumPathComponentLength(const FilePath& path
 #if !defined(OS_ANDROID)
 // This is implemented in file_util_android.cc for that platform.
 bool GetShmemTempDir(bool executable, FilePath* path) {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_AIX)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_AIX) || defined(OS_BSD)
   bool disable_dev_shm = false;
 #if !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS)
   disable_dev_shm = CommandLine::ForCurrentProcess()->HasSwitch(
@@ -1127,7 +1135,7 @@ bool GetShmemTempDir(bool executable, FilePath* path) 
     *path = FilePath("/dev/shm");
     return true;
   }
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_AIX)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_AIX) || defined(OS_BSD)
   return GetTempDir(path);
 }
 #endif  // !defined(OS_ANDROID)
@@ -1165,7 +1173,7 @@ PrefetchResult PreReadFile(const FilePath& file_path,
   // posix_fadvise() is only available in the Android NDK in API 21+. Older
   // versions may have the required kernel support, but don't have enough usage
   // to justify backporting.
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     (defined(OS_ANDROID) && __ANDROID_API__ >= 21)
   File file(file_path, File::FLAG_OPEN | File::FLAG_READ);
   if (!file.IsValid())
@@ -1201,7 +1209,7 @@ PrefetchResult PreReadFile(const FilePath& file_path,
   return internal::PreReadFileSlow(file_path, max_bytes)
              ? PrefetchResult{PrefetchResultCode::kSlowSuccess}
              : PrefetchResult{PrefetchResultCode::kSlowFailed};
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || (defined(OS_ANDROID) &&
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || (defined(OS_ANDROID) &&
         // __ANDROID_API__ >= 21)
 }
 
@@ -1232,7 +1240,7 @@ bool MoveUnsafe(const FilePath& from_path, const FileP
   return true;
 }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
 bool CopyFileContentsWithSendfile(File& infile,
                                   File& outfile,
                                   bool& retry_slow) {
@@ -1246,12 +1254,26 @@ bool CopyFileContentsWithSendfile(File& infile,
   while (file_size - copied > 0) {
     // Don't specify an offset and the kernel will begin reading/writing to the
     // current file offsets.
+#if defined(OS_BSD)
+    int retv = HANDLE_EINTR(sendfile(infile.GetPlatformFile(),
+			        outfile.GetPlatformFile(),
+				copied,
+				file_size - copied,
+				/*hdtr=*/nullptr,
+				&res,
+				0));
+    if (retv != 0) {
+      res = -1;
+      break;
+    }
+#else
     res = HANDLE_EINTR(sendfile(outfile.GetPlatformFile(),
                                 infile.GetPlatformFile(), /*offset=*/nullptr,
                                 /*length=*/file_size - copied));
     if (res <= 0) {
       break;
     }
+#endif
 
     copied += res;
   }
@@ -1265,13 +1287,13 @@ bool CopyFileContentsWithSendfile(File& infile,
 
   return res >= 0;
 }
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
 
 }  // namespace internal
 
 #endif  // !defined(OS_NACL_NONSFI)
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_AIX)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_AIX) || defined(OS_BSD)
 BASE_EXPORT bool IsPathExecutable(const FilePath& path) {
   bool result = false;
   FilePath tmp_file_path;
@@ -1292,6 +1314,6 @@ BASE_EXPORT bool IsPathExecutable(const FilePath& path
   }
   return result;
 }
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_AIX)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_AIX) || defined(OS_BSD)
 
 }  // namespace base
