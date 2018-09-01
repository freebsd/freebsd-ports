--- third_party/googletest/src/googletest/include/gtest/internal/gtest-port.h.orig	2018-08-23 02:51:47.688298000 +0200
+++ third_party/googletest/src/googletest/include/gtest/internal/gtest-port.h	2018-08-23 02:53:09.975152000 +0200
@@ -841,7 +841,7 @@
     (GTEST_OS_WINDOWS || GTEST_OS_CYGWIN || GTEST_OS_SYMBIAN || GTEST_OS_AIX)
 
 // Determines whether test results can be streamed to a socket.
-#if GTEST_OS_LINUX
+#if GTEST_OS_LINUX || GTEST_OS_FREEBSD
 # define GTEST_CAN_STREAM_RESULTS_ 1
 #endif
 
