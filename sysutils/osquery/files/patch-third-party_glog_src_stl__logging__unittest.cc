--- third-party/glog/src/stl_logging_unittest.cc.orig	2015-04-16 17:06:51 UTC
+++ third-party/glog/src/stl_logging_unittest.cc
@@ -41,6 +41,7 @@
 // C++0x isn't enabled by default in GCC and libc++ does not have
 // non-standard ext/* and tr1/unordered_*.
 # if defined(_LIBCPP_VERSION)
+#  define GLOG_STL_LOGGING_FOR_FORWARD_LIST
 #  define GLOG_STL_LOGGING_FOR_UNORDERED
 # else
 #  define GLOG_STL_LOGGING_FOR_EXT_HASH
