--- third_party/crashpad/crashpad/util/posix/close_multiple.cc.orig	2025-12-10 15:04:57 UTC
+++ third_party/crashpad/crashpad/util/posix/close_multiple.cc
@@ -73,7 +73,7 @@ void CloseNowOrOnExec(int fd, bool ebadf_ok) {
 // This is an advantage over looping over all possible file descriptors, because
 // no attempt needs to be made to close file descriptors that are not open.
 bool CloseMultipleNowOrOnExecUsingFDDir(int min_fd, int preserve_fd) {
-#if BUILDFLAG(IS_APPLE)
+#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD)
   static constexpr char kFDDir[] = "/dev/fd";
 #elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
   static constexpr char kFDDir[] = "/proc/self/fd";
