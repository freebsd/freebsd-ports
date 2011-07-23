--- src/galois.cc-orig	2011-07-22 23:34:28.000000000 +0000
+++ src/galois.cc	2011-07-22 23:40:32.000000000 +0000
@@ -89,7 +89,7 @@
   field = stored_galois_fields.create_galois_field(_m, _primpoly);
 }
 
-galois::galois (int nr, int nc, const int& val, const int& _m, const int& _primpoly) : MArray2<int> (nr, nc, val), field (NULL) {
+galois::galois (int nr, int nc, const int& val, const int& _m, const int& _primpoly) : MArray<int> (dim_vector(nr, nc), val), field (NULL) {
   int _n = (1<<_m) - 1;
 
   // Check the validity of the data in the matrix
@@ -101,7 +101,7 @@
   field = stored_galois_fields.create_galois_field(_m, _primpoly);
 }
 
-galois::galois (int nr, int nc, double val, const int& _m, const int& _primpoly) : MArray2<int> (nr, nc, (int)val), field (NULL) {
+galois::galois (int nr, int nc, double val, const int& _m, const int& _primpoly) : MArray<int> (dim_vector(nr, nc), (int)val), field (NULL) {
   int _n = (1<<_m) - 1;
 
   // Check the validity of the data in the matrix
@@ -711,13 +711,13 @@
 boolMatrix
 galois::all (int dim) const
 {
-  return do_mx_red_op<boolMatrix> (*this, dim, mx_inline_all);
+  return do_mx_red_op<bool> (*this, dim, mx_inline_all);
 }
 
 boolMatrix
 galois::any (int dim) const
 {
-  return do_mx_red_op<boolMatrix> (*this, dim, mx_inline_any);
+  return do_mx_red_op<bool> (*this, dim, mx_inline_any);
 }
 
 galois
