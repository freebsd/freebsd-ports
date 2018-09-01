--- third_party/googletest/src/googletest/src/gtest.cc.orig	2018-08-23 02:47:05.784079000 +0200
+++ third_party/googletest/src/googletest/src/gtest.cc	2018-08-23 02:47:43.415365000 +0200
@@ -128,6 +128,7 @@
 
 #if GTEST_CAN_STREAM_RESULTS_
 # include <arpa/inet.h>  // NOLINT
+# include <sys/socket.h> // NOLINT
 # include <netdb.h>  // NOLINT
 # include <sys/socket.h>  // NOLINT
 # include <sys/types.h>  // NOLINT
