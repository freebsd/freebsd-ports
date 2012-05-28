--- content/browser/zygote_main_linux.cc.orig	2012-05-09 10:01:22.000000000 +0300
+++ content/browser/zygote_main_linux.cc	2012-05-20 00:36:19.660106416 +0300
@@ -703,7 +703,7 @@
 // TODO(sergeyu): Currently this code doesn't work properly under ASAN
 // - it crashes content_unittests. Make sure it works properly and
 // enable it here. http://crbug.com/123263
-#if !defined(ADDRESS_SANITIZER)
+#if !defined(ADDRESS_SANITIZER) && !defined(OS_BSD)
 
 static void InitLibcFileIOFunctions() {
   g_libc_fopen = reinterpret_cast<FopenFunction>(
@@ -714,9 +714,9 @@
   if (!g_libc_fopen) {
     LOG(FATAL) << "Failed to get fopen() from libc.";
   } else if (!g_libc_fopen64) {
-#if !defined(OS_OPENBSD) && !defined(OS_FREEBSD)
+#if !defined(OS_BSD)
     LOG(WARNING) << "Failed to get fopen64() from libc. Using fopen() instead.";
-#endif  // !defined(OS_OPENBSD) && !defined(OS_FREEBSD)
+#endif  // !defined(OS_BSD)
     g_libc_fopen64 = g_libc_fopen;
   }
 
@@ -897,7 +897,7 @@
     SkiaFontConfigSetImplementation(
         new FontConfigIPC(kMagicSandboxIPCDescriptor));
 
-#if !defined(OS_OPENBSD)
+#if !defined(OS_BSD)
     // Previously, we required that the binary be non-readable. This causes the
     // kernel to mark the process as non-dumpable at startup. The thinking was
     // that, although we were putting the renderers into a PID namespace (with
