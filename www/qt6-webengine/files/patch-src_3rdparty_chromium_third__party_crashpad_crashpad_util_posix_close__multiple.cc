--- src/3rdparty/chromium/third_party/crashpad/crashpad/util/posix/close_multiple.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/third_party/crashpad/crashpad/util/posix/close_multiple.cc
@@ -72,7 +72,7 @@ bool CloseMultipleNowOrOnExecUsingFDDir(int min_fd, in
 // This is an advantage over looping over all possible file descriptors, because
 // no attempt needs to be made to close file descriptors that are not open.
 bool CloseMultipleNowOrOnExecUsingFDDir(int min_fd, int preserve_fd) {
-#if BUILDFLAG(IS_APPLE)
+#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD)
   static constexpr char kFDDir[] = "/dev/fd";
 #elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
   static constexpr char kFDDir[] = "/proc/self/fd";
