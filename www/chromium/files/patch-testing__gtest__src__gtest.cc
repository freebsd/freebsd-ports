--- testing/gtest/src/gtest.cc.orig	2011-09-14 23:58:20.000000000 +0300
+++ testing/gtest/src/gtest.cc	2011-09-15 00:01:10.000000000 +0300
@@ -114,6 +114,10 @@
 
 #endif  // GTEST_OS_LINUX
 
+#if GTEST_OS_FREEBSD
+# include <sys/socket.h>
+#endif
+
 #if GTEST_HAS_EXCEPTIONS
 # include <stdexcept>
 #endif
