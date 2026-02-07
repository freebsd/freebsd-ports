--- base/threading/platform_thread_internal_posix.cc.orig	2026-01-14 08:33:23 UTC
+++ base/threading/platform_thread_internal_posix.cc
@@ -31,10 +31,19 @@ ThreadType NiceValueToThreadTypeForTest(int nice_value
 }
 
 int GetCurrentThreadNiceValue() {
+#if BUILDFLAG(IS_BSD)
+  NOTIMPLEMENTED();
+  return 0;
+#else
   return GetThreadNiceValue(PlatformThreadId{0});
+#endif
 }
 
 int GetThreadNiceValue(PlatformThreadId id) {
+#if BUILDFLAG(IS_BSD)
+  NOTIMPLEMENTED();
+  return 0;
+#else
   // Need to clear errno before calling getpriority():
   // http://man7.org/linux/man-pages/man2/getpriority.2.html
   errno = 0;
@@ -46,9 +55,15 @@ int GetThreadNiceValue(PlatformThreadId id) {
   }
 
   return nice_value;
+#endif
 }
 
 bool SetThreadNiceFromType(PlatformThreadId thread_id, ThreadType thread_type) {
+#if BUILDFLAG(IS_BSD)
+  // pledge(2) violation
+  NOTIMPLEMENTED();
+  return true;
+#else
   // setpriority(2) should change the whole thread group's (i.e. process)
   // priority. However, as stated in the bugs section of
   // http://man7.org/linux/man-pages/man2/getpriority.2.html: "under the current
@@ -64,6 +79,7 @@ bool SetThreadNiceFromType(PlatformThreadId thread_id,
     return false;
   }
   return true;
+#endif
 }
 
 }  // namespace base::internal
