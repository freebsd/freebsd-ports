--- third_party/crashpad/crashpad/util/posix/close_multiple.cc.orig	2018-07-19 19:49:00.959630000 +0200
+++ third_party/crashpad/crashpad/util/posix/close_multiple.cc	2018-07-19 19:49:23.277639000 +0200
@@ -71,7 +71,7 @@
 // This is an advantage over looping over all possible file descriptors, because
 // no attempt needs to be made to close file descriptors that are not open.
 bool CloseMultipleNowOrOnExecUsingFDDir(int min_fd, int preserve_fd) {
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
   static constexpr char kFDDir[] = "/dev/fd";
 #elif defined(OS_LINUX) || defined(OS_ANDROID)
   static constexpr char kFDDir[] = "/proc/self/fd";
