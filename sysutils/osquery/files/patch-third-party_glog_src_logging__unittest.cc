--- third-party/glog/src/logging_unittest.cc.orig	2015-05-10 14:03:15 UTC
+++ third-party/glog/src/logging_unittest.cc
@@ -61,6 +61,7 @@ DECLARE_string(log_backtrace_at);  // lo
 
 #ifdef HAVE_LIB_GFLAGS
 #include <gflags/gflags.h>
+using namespace gflags;
 #endif
 
 #ifdef HAVE_LIB_GMOCK
