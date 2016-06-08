--- ./testing/gtest/include/gtest/internal/gtest-port.h.orig	2014-04-30 22:43:26.000000000 +0200
+++ ./testing/gtest/include/gtest/internal/gtest-port.h	2014-05-04 14:38:48.000000000 +0200
@@ -265,6 +265,8 @@
 # define GTEST_OS_NACL 1
 #elif defined __OpenBSD__
 # define GTEST_OS_OPENBSD 1
+#elif defined __FreeBSD__
+# define GTEST_OS_FREEBSD 1
 #elif defined __QNX__
 # define GTEST_OS_QNX 1
 #endif  // __CYGWIN__
@@ -477,7 +479,7 @@
 // To disable threading support in Google Test, add -DGTEST_HAS_PTHREAD=0
 // to your compiler flags.
 # define GTEST_HAS_PTHREAD (GTEST_OS_LINUX || GTEST_OS_MAC || GTEST_OS_HPUX \
-    || GTEST_OS_QNX)
+    || GTEST_OS_QNX || GTEST_OS_FREEBSD)
 #endif  // GTEST_HAS_PTHREAD
 
 #if GTEST_HAS_PTHREAD
@@ -646,7 +648,7 @@
      (GTEST_OS_MAC && !GTEST_OS_IOS) || GTEST_OS_IOS_SIMULATOR || \
      (GTEST_OS_WINDOWS_DESKTOP && _MSC_VER >= 1400) || \
      GTEST_OS_WINDOWS_MINGW || GTEST_OS_AIX || GTEST_OS_HPUX || \
-     GTEST_OS_OPENBSD || GTEST_OS_QNX)
+     GTEST_OS_OPENBSD || GTEST_OS_FREEBSD || GTEST_OS_QNX)
 # define GTEST_HAS_DEATH_TEST 1
 # include <vector>  // NOLINT
 #endif
