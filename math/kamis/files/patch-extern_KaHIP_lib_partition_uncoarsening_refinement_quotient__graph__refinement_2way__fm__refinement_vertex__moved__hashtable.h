--- extern/KaHIP/lib/partition/uncoarsening/refinement/quotient_graph_refinement/2way_fm_refinement/vertex_moved_hashtable.h.orig	2022-07-01 08:56:00 UTC
+++ extern/KaHIP/lib/partition/uncoarsening/refinement/quotient_graph_refinement/2way_fm_refinement/vertex_moved_hashtable.h
@@ -13,7 +13,7 @@
 #include "definitions.h"
 #include "limits.h"
 
-using namespace __gnu_cxx;
+//using namespace __gnu_cxx;
 
 struct compare_nodes {
         bool operator()(const NodeID lhs, const NodeID rhs) const {
