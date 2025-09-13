--- base/threading/platform_thread_internal_posix.cc.orig	2025-09-11 13:19:19 UTC
+++ base/threading/platform_thread_internal_posix.cc
@@ -31,6 +31,10 @@ ThreadPriorityForTest NiceValueToThreadPriorityForTest
 }
 
 int GetCurrentThreadNiceValue() {
+#if BUILDFLAG(IS_BSD)
+  NOTIMPLEMENTED();
+  return 0;
+#else
   // Need to clear errno before calling getpriority():
   // http://man7.org/linux/man-pages/man2/getpriority.2.html
   errno = 0;
@@ -42,6 +46,7 @@ int GetCurrentThreadNiceValue() {
   }
 
   return nice_value;
+#endif
 }
 
 }  // namespace base::internal
