--- src/StatisticsStrategy.cpp.orig	2011-09-23 20:09:12 UTC
+++ src/StatisticsStrategy.cpp
@@ -140,7 +140,7 @@ double StatisticsStrategy::StatTracker::getAvgSubGenCo
   if (_nodeCount == 0)
     return 0.0;
   else {
-    mpz_class q = mpq_class(_subGenSum) / _nodeCount;
+    mpq_class q = mpq_class(_subGenSum) / _nodeCount;
     return q.get_d();
   }
 }
