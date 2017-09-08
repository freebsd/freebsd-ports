--- base/native_library_posix.cc.orig	2017-07-25 21:04:48.000000000 +0200
+++ base/native_library_posix.cc	2017-08-02 21:02:05.991380000 +0200
@@ -30,7 +30,7 @@
   // http://crbug.com/17943, http://crbug.com/17557, http://crbug.com/36892,
   // and http://crbug.com/40794.
   int flags = RTLD_LAZY;
-#if defined(OS_ANDROID) || !defined(RTLD_DEEPBIND)
+#if defined(OS_ANDROID) || !defined(RTLD_DEEPBIND) || defined(OS_BSD)
   // Certain platforms don't define RTLD_DEEPBIND. Android dlopen() requires
   // further investigation, as it might vary across versions. Crash here to
   // warn developers that they're trying to rely on uncertain behavior.
