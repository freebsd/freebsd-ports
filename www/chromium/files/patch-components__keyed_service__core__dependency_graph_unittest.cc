--- components/keyed_service/core/dependency_graph_unittest.cc.orig	2016-03-05 21:17:52.372555224 +0100
+++ components/keyed_service/core/dependency_graph_unittest.cc	2016-03-05 21:18:04.371555206 +0100
@@ -9,7 +9,11 @@
 #include "components/keyed_service/core/dependency_graph.h"
 #include "components/keyed_service/core/dependency_node.h"
 #include "testing/gtest/include/gtest/gtest.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 namespace {
 
