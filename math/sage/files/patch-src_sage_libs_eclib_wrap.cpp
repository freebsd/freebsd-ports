--- src/sage/libs/eclib/wrap.cpp.orig	2021-03-16 21:40:43 UTC
+++ src/sage/libs/eclib/wrap.cpp
@@ -178,11 +178,11 @@ int mw_rank(struct mw* m)
 }
 
 /* Returns index and unsat long array, which user must deallocate */
-int mw_saturate(struct mw* m, bigint* index, char** unsat,
-                       long sat_bd, int odd_primes_only)
+int mw_saturate(struct mw* m, long* index, char** unsat,
+                       long sat_bd, long sat_low_bd)
 {
   vector<long> v;
-  int s = m->saturate(*index, v, sat_bd, odd_primes_only);
+  int s = m->saturate(*index, v, sat_bd, sat_low_bd);
   ostringstream instore;
   instore << v;
   *unsat  = stringstream_to_char(instore);
@@ -236,9 +236,9 @@ long two_descent_get_certain(const two_descent* t)
   return t->getcertain();
 }
 
-void two_descent_saturate(struct two_descent* t, long sat_bd)
+void two_descent_saturate(struct two_descent* t, long sat_bd, long sat_low_bd)
 {
-  t->saturate(sat_bd);
+  t->saturate(sat_bd, sat_low_bd);
 }
 
 double two_descent_regulator(struct two_descent* t)
