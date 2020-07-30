--- third_party/googletest/src/googletest/src/gtest.cc.orig	2020-07-07 22:03:20 UTC
+++ third_party/googletest/src/googletest/src/gtest.cc
@@ -119,6 +119,7 @@
 
 #if GTEST_CAN_STREAM_RESULTS_
 # include <arpa/inet.h>  // NOLINT
+# include <sys/socket.h> // NOLINT
 # include <netdb.h>  // NOLINT
 # include <sys/socket.h>  // NOLINT
 # include <sys/types.h>  // NOLINT
