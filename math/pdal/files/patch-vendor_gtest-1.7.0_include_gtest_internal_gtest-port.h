--- vendor/gtest-1.7.0/include/gtest/internal/gtest-port.h.orig	2016-03-24 21:27:13 UTC
+++ vendor/gtest-1.7.0/include/gtest/internal/gtest-port.h
@@ -92,6 +92,7 @@
 // the given platform; otherwise undefined):
 //   GTEST_OS_AIX      - IBM AIX
 //   GTEST_OS_CYGWIN   - Cygwin
+//   GTEST_OS_FREEBSD     - FreeBSD
 //   GTEST_OS_HPUX     - HP-UX
 //   GTEST_OS_LINUX    - Linux
 //     GTEST_OS_LINUX_ANDROID - Google Android
@@ -267,6 +268,8 @@
 # define GTEST_OS_OPENBSD 1
 #elif defined __QNX__
 # define GTEST_OS_QNX 1
+#elif defined __FreeBSD__ || defined __DragonFly__
+# define GTEST_OS_FREEBSD 1
 #endif  // __CYGWIN__
 
 #ifndef GTEST_LANG_CXX11
@@ -646,7 +649,7 @@ using ::std::tuple_size;
      (GTEST_OS_MAC && !GTEST_OS_IOS) || GTEST_OS_IOS_SIMULATOR || \
      (GTEST_OS_WINDOWS_DESKTOP && _MSC_VER >= 1400) || \
      GTEST_OS_WINDOWS_MINGW || GTEST_OS_AIX || GTEST_OS_HPUX || \
-     GTEST_OS_OPENBSD || GTEST_OS_QNX)
+     GTEST_OS_OPENBSD || GTEST_OS_QNX || GTEST_OS_FREEBSD)
 # define GTEST_HAS_DEATH_TEST 1
 # include <vector>  // NOLINT
 #endif
