--- base/files/file_util_posix.cc.orig	2020-11-13 06:36:34 UTC
+++ base/files/file_util_posix.cc
@@ -412,7 +412,7 @@ bool CreatePipe(ScopedFD* read_fd, ScopedFD* write_fd,
 }
 
 bool CreateLocalNonBlockingPipe(int fds[2]) {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   return pipe2(fds, O_CLOEXEC | O_NONBLOCK) == 0;
 #else
   int raw_fds[2];
@@ -947,8 +947,12 @@ bool AllocateFileRegion(File* file, int64_t offset, si
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
@@ -1172,7 +1176,7 @@ PrefetchResult PreReadFile(const FilePath& file_path,
   // posix_fadvise() is only available in the Android NDK in API 21+. Older
   // versions may have the required kernel support, but don't have enough usage
   // to justify backporting.
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     (defined(OS_ANDROID) && __ANDROID_API__ >= 21)
   File file(file_path, File::FLAG_OPEN | File::FLAG_READ);
   if (!file.IsValid())
@@ -1208,7 +1212,7 @@ PrefetchResult PreReadFile(const FilePath& file_path,
   return internal::PreReadFileSlow(file_path, max_bytes)
              ? PrefetchResult{PrefetchResultCode::kSlowSuccess}
              : PrefetchResult{PrefetchResultCode::kSlowFailed};
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || (defined(OS_ANDROID) &&
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || (defined(OS_ANDROID) &&
         // __ANDROID_API__ >= 21)
 }
 
@@ -1243,7 +1247,7 @@ bool MoveUnsafe(const FilePath& from_path, const FileP
 
 #endif  // !defined(OS_NACL_NONSFI)
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_AIX)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_AIX) || defined(OS_BSD)
 BASE_EXPORT bool IsPathExecutable(const FilePath& path) {
   bool result = false;
   FilePath tmp_file_path;
@@ -1264,6 +1268,6 @@ BASE_EXPORT bool IsPathExecutable(const FilePath& path
   }
   return result;
 }
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_AIX)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_AIX) || defined(OS_BSD)
 
 }  // namespace base
