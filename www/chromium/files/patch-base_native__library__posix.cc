--- base/native_library_posix.cc.orig	2016-10-06 04:02:08.000000000 +0300
+++ base/native_library_posix.cc	2016-10-14 03:14:48.329757000 +0300
@@ -35,7 +35,7 @@
   // versions. Crash here to warn developers that they're trying to rely on
   // uncertain behavior.
   CHECK(!options.prefer_own_symbols);
-#else
+#elif !defined(OS_BSD)
   if (options.prefer_own_symbols)
     flags |= RTLD_DEEPBIND;
 #endif
