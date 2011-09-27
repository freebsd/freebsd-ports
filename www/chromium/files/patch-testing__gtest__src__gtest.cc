--- testing/gtest/src/gtest.cc.orig	2011-09-14 11:19:34.000000000 +0300
+++ testing/gtest/src/gtest.cc	2011-09-27 00:34:58.000000000 +0300
@@ -114,6 +114,10 @@
 
 #endif  // GTEST_OS_LINUX
 
+#if GTEST_OS_FREEBSD
+# include <sys/socket.h>
+#endif
+
 #if GTEST_HAS_EXCEPTIONS
 # include <stdexcept>
 #endif
@@ -1621,7 +1625,7 @@
 
 #if GTEST_OS_WINDOWS
   return _wcsicmp(lhs, rhs) == 0;
-#elif GTEST_OS_LINUX && !GTEST_OS_LINUX_ANDROID
+#elif GTEST_OS_LINUX && !GTEST_OS_LINUX_ANDROID && !GTEST_OS_FREEBSD
   return wcscasecmp(lhs, rhs) == 0;
 #else
   // Android, Mac OS X and Cygwin don't define wcscasecmp.
