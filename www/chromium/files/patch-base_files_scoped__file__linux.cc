--- base/files/scoped_file_linux.cc.orig	2021-07-28 11:34:50 UTC
+++ base/files/scoped_file_linux.cc
@@ -80,12 +80,20 @@ bool IsFDOwned(int fd) {
 
 extern "C" {
 
+#if defined(OS_FREEBSD)
+int __sys_close(int);
+#else
 int __close(int);
+#endif
 
 __attribute__((visibility("default"), noinline)) int close(int fd) {
   if (base::IsFDOwned(fd) && g_is_ownership_enforced)
     CrashOnFdOwnershipViolation();
+#if defined(OS_FREEBSD)
+  return __sys_close(fd);
+#else
   return __close(fd);
+#endif
 }
 
 }  // extern "C"
