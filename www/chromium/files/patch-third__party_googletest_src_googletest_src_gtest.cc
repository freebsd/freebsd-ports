--- third_party/googletest/src/googletest/src/gtest.cc.orig	2020-11-13 06:42:16 UTC
+++ third_party/googletest/src/googletest/src/gtest.cc
@@ -117,6 +117,7 @@
 
 #if GTEST_CAN_STREAM_RESULTS_
 # include <arpa/inet.h>  // NOLINT
+# include <sys/socket.h> // NOLINT
 # include <netdb.h>  // NOLINT
 # include <sys/socket.h>  // NOLINT
 # include <sys/types.h>  // NOLINT
