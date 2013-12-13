--- tools/gtest-1.6.0/include/gtest/internal/gtest-port.h.orig	2011-05-07 10:25:30.000000000 +0800
+++ tools/gtest-1.6.0/include/gtest/internal/gtest-port.h	2013-09-12 17:39:09.000000000 +0800
@@ -204,6 +204,8 @@
 #define GTEST_NAME_ "Google Test"
 #define GTEST_PROJECT_URL_ "http://code.google.com/p/googletest/"
 
+#define GTEST_USE_OWN_TR1_TUPLE 1
+
 // Determines the version of gcc that is used to compile this.
 #ifdef __GNUC__
 // 40302 means version 4.3.2.
