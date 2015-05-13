--- third-party/glog/src/googletest.h.orig	2015-04-16 17:06:51 UTC
+++ third-party/glog/src/googletest.h
@@ -58,6 +58,10 @@
 
 #include "base/commandlineflags.h"
 
+#ifdef HAVE_LIB_GFLAGS
+#include <gflags/gflags.h>
+using namespace gflags;
+#endif
 using std::map;
 using std::string;
 using std::vector;
