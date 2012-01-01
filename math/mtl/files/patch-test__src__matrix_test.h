--- test/src/matrix_test.h.orig	2007-04-10 16:03:10.000000000 -0400
+++ test/src/matrix_test.h	2012-01-01 07:40:34.000000000 -0500
@@ -52,6 +52,9 @@
 
 #include "fill_matrix.h"
 
+template <class Matrix>
+void
+do_test(Matrix& A, std::string test_name);
 
 template <class Matrix>
 void
