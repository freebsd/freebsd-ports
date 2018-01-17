--- src/3rdparty/chromium/testing/gtest/src/gtest.cc.orig	2017-01-26 00:50:07 UTC
+++ src/3rdparty/chromium/testing/gtest/src/gtest.cc
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
