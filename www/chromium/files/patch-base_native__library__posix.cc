--- base/native_library_posix.cc.orig	2019-03-11 22:00:51 UTC
+++ base/native_library_posix.cc
@@ -29,7 +29,7 @@ NativeLibrary LoadNativeLibraryWithOptions(const FileP
   // http://crbug.com/17943, http://crbug.com/17557, http://crbug.com/36892,
   // and http://crbug.com/40794.
   int flags = RTLD_LAZY;
-#if defined(OS_ANDROID) || !defined(RTLD_DEEPBIND)
+#if defined(OS_ANDROID) || !defined(RTLD_DEEPBIND) || defined(OS_BSD)
   // Certain platforms don't define RTLD_DEEPBIND. Android dlopen() requires
   // further investigation, as it might vary across versions. Crash here to
   // warn developers that they're trying to rely on uncertain behavior.
