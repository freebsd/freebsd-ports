--- lib/mis/kernel/ParFastKer/fast_reductions/src/MaximumMatching.cpp.orig	2022-07-01 08:50:58 UTC
+++ lib/mis/kernel/ParFastKer/fast_reductions/src/MaximumMatching.cpp
@@ -44,10 +44,12 @@
  * */ 
  
 
-#include <parallel/numeric>
+#include <numeric>
 #include "MaximumMatching.h"
 #include <sys/resource.h>
 
+#include <omp.h>
+
 void increaseStackLimit(unsigned const size) {
 
     const rlim_t kStackSize = size * 1024 * 1024;   // size = min stack size in MB
@@ -83,7 +85,7 @@ MaximumMatching::MaximumMatching(std::vector<std::vect
 		degree[i] = adjacencyArray[i].size();
 		degree[i + numVertices] = adjacencyArray[i].size();
 	}
-	auto end_ptr = __gnu_parallel::partial_sum(degree, degree + (G->n), (G->vtx_pointer) + 1);
+	auto end_ptr = std::partial_sum(degree, degree + (G->n), (G->vtx_pointer) + 1);
 	assert(end_ptr == &(G->vtx_pointer[2 * numVertices]) + 1);
 	G->vtx_pointer[0] = 0;
 	long numEdges = G->vtx_pointer[2 * numVertices];
@@ -148,7 +150,7 @@ void MaximumMatching::LoadGraph(std::vector<SparseArra
 		degree[i] = deg;
 		degree[i + G->nrows] = deg;
 	}
-	auto end_ptr = __gnu_parallel::partial_sum(degree, degree + (G->n), (G->vtx_pointer) + 1);
+	auto end_ptr = std::partial_sum(degree, degree + (G->n), (G->vtx_pointer) + 1);
 	assert(end_ptr == &(G->vtx_pointer[G->n]) + 1);
 	G->vtx_pointer[0] = 0;
 	long numEdges = G->vtx_pointer[G->n];
