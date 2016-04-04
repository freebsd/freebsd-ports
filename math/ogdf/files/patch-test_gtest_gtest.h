--- test/gtest/gtest.h.orig	2015-05-29 15:37:01 UTC
+++ test/gtest/gtest.h
@@ -181,6 +181,7 @@
 // the given platform; otherwise undefined):
 //   GTEST_OS_AIX      - IBM AIX
 //   GTEST_OS_CYGWIN   - Cygwin
+//   GTEST_OS_FREEBSD  - FreeBSD
 //   GTEST_OS_HPUX     - HP-UX
 //   GTEST_OS_LINUX    - Linux
 //     GTEST_OS_LINUX_ANDROID - Google Android
@@ -337,6 +338,9 @@
 # define GTEST_OS_HPUX 1
 #elif defined __native_client__
 # define GTEST_OS_NACL 1
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
+# define GTEST_OS_FREEBSD 1
+# define GTEST_USE_OWN_TR1_TUPLE 1
 #endif  // __CYGWIN__
 
 // Brings in definitions for functions used in the testing::internal::posix
@@ -1602,7 +1606,7 @@ inline bool operator!=(const GTEST_10_TU
 // pops up a dialog window that cannot be suppressed programmatically.
 #if (GTEST_OS_LINUX || GTEST_OS_MAC || GTEST_OS_CYGWIN || GTEST_OS_SOLARIS || \
      (GTEST_OS_WINDOWS_DESKTOP && _MSC_VER >= 1400) || \
-     GTEST_OS_WINDOWS_MINGW || GTEST_OS_AIX || GTEST_OS_HPUX)
+     GTEST_OS_WINDOWS_MINGW || GTEST_OS_AIX || GTEST_OS_HPUX || GTEST_OS_FREEBSD )
 # define GTEST_HAS_DEATH_TEST 1
 # include <vector>  // NOLINT
 #endif
