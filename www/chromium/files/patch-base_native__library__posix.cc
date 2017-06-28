--- base/native_library_posix.cc.orig	2017-06-05 19:03:00 UTC
+++ base/native_library_posix.cc
@@ -35,7 +35,7 @@ NativeLibrary LoadNativeLibraryWithOptions(const FileP
   // further investigation, as it might vary across versions. Crash here to
   // warn developers that they're trying to rely on uncertain behavior.
   CHECK(!options.prefer_own_symbols);
-#else
+#elif !defined(OS_BSD)
   if (options.prefer_own_symbols)
     flags |= RTLD_DEEPBIND;
 #endif
