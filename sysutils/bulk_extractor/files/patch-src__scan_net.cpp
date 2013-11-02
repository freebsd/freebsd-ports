--- ./src/scan_net.cpp.orig	2013-08-18 16:39:17.000000000 +0000
+++ ./src/scan_net.cpp	2013-10-19 13:09:32.000000000 +0000
@@ -27,7 +27,16 @@
 #include "be13_api/utils.h"
 
 #include <set>
+#ifdef __clang__
+#if __has_include(<unordered_set>)
+#define HAVE_CXX11_UNORDERED_SET 1
+#endif
+#endif
+#ifdef HAVE_CXX11_UNORDERED_SET
+#include <unordered_set>
+#else
 #include <tr1/unordered_set>
+#endif
 
 #include <sys/types.h>
 #include <stdlib.h>
@@ -603,7 +612,11 @@
 	return *this;			// no-op
     }
 public:
+#ifdef HAVE_CXX11_UNORDERED_SET
+    typedef std::unordered_set<const void *> packetset;
+#else
     typedef std::tr1::unordered_set<const void *> packetset;
+#endif
     feature_recorder_set &fs;
     packetset ps;
     feature_recorder *ip_recorder;
