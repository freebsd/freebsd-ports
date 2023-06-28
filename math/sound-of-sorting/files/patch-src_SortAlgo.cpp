--- src/SortAlgo.cpp.orig	2017-12-23 08:39:32 UTC
+++ src/SortAlgo.cpp
@@ -37,6 +37,7 @@
 #include <numeric>
 #include <limits>
 #include <inttypes.h>
+#include <random>
 
 typedef ArrayItem value_type;
 
@@ -1076,7 +1077,9 @@ void BogoSort(SortArray& A)
         if (BogoCheckSorted(A)) break;
 
         // pick a random permutation of indexes
-        std::random_shuffle(perm.begin(), perm.end());
+        std::random_device rng;
+        std::mt19937 urng(rng());
+        std::shuffle(perm.begin(), perm.end(), urng);
 
         // permute array in-place
         std::vector<char> pmark(A.size(), 0);
