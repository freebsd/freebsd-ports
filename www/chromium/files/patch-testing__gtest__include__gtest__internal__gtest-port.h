--- testing/gtest/include/gtest/internal/gtest-port.h.orig	2012-12-20 10:02:55.000000000 +0200
+++ testing/gtest/include/gtest/internal/gtest-port.h	2013-01-06 22:58:55.000000000 +0200
@@ -261,6 +261,8 @@
 # define GTEST_OS_NACL 1
 #elif defined __OpenBSD__
 # define GTEST_OS_OPENBSD 1
+#elif defined __FreeBSD__
+# define GTEST_OS_FREEBSD 1
 #elif defined __QNX__
 # define GTEST_OS_QNX 1
 #endif  // __CYGWIN__
