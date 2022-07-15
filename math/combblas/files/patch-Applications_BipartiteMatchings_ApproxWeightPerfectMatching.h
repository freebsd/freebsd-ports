--- Applications/BipartiteMatchings/ApproxWeightPerfectMatching.h.orig	2022-07-15 16:38:29 UTC
+++ Applications/BipartiteMatchings/ApproxWeightPerfectMatching.h
@@ -12,8 +12,8 @@
 #include "CombBLAS/CombBLAS.h"
 #include "BPMaximalMatching.h"
 #include "BPMaximumMatching.h"
-#include <parallel/algorithm>
-#include <parallel/numeric>
+#include <algorithm>
+//#include <parallel/numeric>
 #include <memory>
 #include <limits>
 
@@ -563,7 +563,7 @@ std::vector< std::tuple<IT,IT,IT,NT> > Phase2(const AW
     double tstart = MPI_Wtime();
     
     // Step 1: Sort for effecient searching of indices
-    __gnu_parallel::sort(recvTuples.begin(), recvTuples.end());
+    sort(recvTuples.begin(), recvTuples.end());
     std::vector<std::vector<std::tuple<IT,IT, IT, NT>>> tempTuples1 (param.nprocs);
     
     std::vector<int> sendcnt(param.nprocs,0); // number items to be sent to each processor
