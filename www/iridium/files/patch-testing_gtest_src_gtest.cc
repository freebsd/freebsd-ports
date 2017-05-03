--- testing/gtest/src/gtest.cc.orig	2017-04-19 19:07:41 UTC
+++ testing/gtest/src/gtest.cc
@@ -122,6 +122,10 @@
 
 #endif  // GTEST_OS_LINUX
 
+#if GTEST_OS_FREEBSD
+# include <sys/socket.h>
+#endif
+
 #if GTEST_HAS_EXCEPTIONS
 # include <stdexcept>
 #endif
@@ -1930,7 +1934,7 @@ bool String::CaseInsensitiveWideCStringE
 
 #if GTEST_OS_WINDOWS
   return _wcsicmp(lhs, rhs) == 0;
-#elif GTEST_OS_LINUX && !GTEST_OS_LINUX_ANDROID
+#elif GTEST_OS_LINUX && !GTEST_OS_LINUX_ANDROID && !GTEST_OS_FREEBSD
   return wcscasecmp(lhs, rhs) == 0;
 #else
   // Android, Mac OS X and Cygwin don't define wcscasecmp.
