--- ./testing/gtest/src/gtest.cc.orig	2014-08-20 21:03:23.000000000 +0200
+++ ./testing/gtest/src/gtest.cc	2014-08-22 15:06:26.000000000 +0200
@@ -117,6 +117,10 @@
 
 #endif  // GTEST_OS_LINUX
 
+#if GTEST_OS_FREEBSD
+# include <sys/socket.h>
+#endif
+
 #if GTEST_HAS_EXCEPTIONS
 # include <stdexcept>
 #endif
@@ -1592,7 +1596,7 @@
 
 #if GTEST_OS_WINDOWS
   return _wcsicmp(lhs, rhs) == 0;
-#elif GTEST_OS_LINUX && !GTEST_OS_LINUX_ANDROID
+#elif GTEST_OS_LINUX && !GTEST_OS_LINUX_ANDROID && !GTEST_OS_FREEBSD
   return wcscasecmp(lhs, rhs) == 0;
 #else
   // Android, Mac OS X and Cygwin don't define wcscasecmp.
