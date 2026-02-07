--- KameshCode/graph500_2D_SC11/src/create_graph.cc.orig	2022-07-15 16:38:12 UTC
+++ KameshCode/graph500_2D_SC11/src/create_graph.cc
@@ -16,7 +16,7 @@ extern "C" {
 #define USE_GNU_PARALLELMODE 0
 
 #if USE_GNU_PARALLELMODE
-#include <parallel/algorithm>
+#include <algorithm>
 #endif
 
 #define TIME_GRAPHCREATE_STEPS 0
