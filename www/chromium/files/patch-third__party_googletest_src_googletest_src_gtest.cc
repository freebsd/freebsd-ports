--- third_party/googletest/src/googletest/src/gtest.cc.orig	2020-09-08 19:19:55 UTC
+++ third_party/googletest/src/googletest/src/gtest.cc
@@ -117,6 +117,7 @@
 
 #if GTEST_CAN_STREAM_RESULTS_
 # include <arpa/inet.h>  // NOLINT
+# include <sys/socket.h> // NOLINT
 # include <netdb.h>  // NOLINT
 # include <sys/socket.h>  // NOLINT
 # include <sys/types.h>  // NOLINT
