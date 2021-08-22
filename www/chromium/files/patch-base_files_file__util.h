--- base/files/file_util.h.orig	2021-07-19 18:45:05 UTC
+++ base/files/file_util.h
@@ -284,14 +284,14 @@ BASE_EXPORT bool SetPosixFilePermissions(const FilePat
 BASE_EXPORT bool ExecutableExistsInPath(Environment* env,
                                         const FilePath::StringType& executable);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_AIX)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_AIX) || defined(OS_BSD)
 // Determine if files under a given |path| can be mapped and then mprotect'd
 // PROT_EXEC. This depends on the mount options used for |path|, which vary
 // among different Linux distributions and possibly local configuration. It also
 // depends on details of kernel--ChromeOS uses the noexec option for /dev/shm
 // but its kernel allows mprotect with PROT_EXEC anyway.
 BASE_EXPORT bool IsPathExecutable(const FilePath& path);
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_AIX)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_AIX) || defined(OS_BSD)
 
 #endif  // OS_POSIX
 
@@ -614,7 +614,7 @@ BASE_EXPORT bool VerifyPathControlledByAdmin(const bas
 // the directory |path|, in the number of FilePath::CharType, or -1 on failure.
 BASE_EXPORT int GetMaximumPathComponentLength(const base::FilePath& path);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_AIX)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_AIX) || defined(OS_BSD)
 // Broad categories of file systems as returned by statfs() on Linux.
 enum FileSystemType {
   FILE_SYSTEM_UNKNOWN,  // statfs failed.
@@ -661,7 +661,7 @@ BASE_EXPORT bool CopyAndDeleteDirectory(const FilePath
                                         const FilePath& to_path);
 #endif  // defined(OS_WIN)
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
 // CopyFileContentsWithSendfile will use the sendfile(2) syscall to perform a
 // file copy without moving the data between kernel and userspace. This is much
 // more efficient than sequences of read(2)/write(2) calls. The |retry_slow|
@@ -673,7 +673,7 @@ BASE_EXPORT bool CopyAndDeleteDirectory(const FilePath
 BASE_EXPORT bool CopyFileContentsWithSendfile(File& infile,
                                               File& outfile,
                                               bool& retry_slow);
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
 
 // Used by PreReadFile() when no kernel support for prefetching is available.
 bool PreReadFileSlow(const FilePath& file_path, int64_t max_bytes);
