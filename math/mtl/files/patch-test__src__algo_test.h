--- test/src/algo_test.h.orig	2007-04-10 16:03:10.000000000 -0400
+++ test/src/algo_test.h	2012-01-01 08:04:04.000000000 -0500
@@ -8,6 +8,28 @@
 using mtl::dense1D;
 
 template <class Matrix>
+void
+set_diagonal_test(std::string test_name, Matrix& A, bool& success)
+{
+  if (A.is_unit()) {
+    std::cout << test_name.c_str() << " skipping set_diagonal" << std::endl;
+    return;
+  }
+  typedef typename mtl::matrix_traits<Matrix>::value_type T;
+  typedef typename mtl::matrix_traits<Matrix>::size_type Int;
+  // set_diagnal
+  Int i;
+  mtl::set_diagonal(A, T(1));
+  
+  for (i = 0; i < A.nrows() && i < A.ncols(); ++i)
+    if (A(i,i) != T(1)) {
+      std::cout << test_name.c_str() << " failed set_diagnal(A,a) *****" << std::endl;
+      success = false;
+      break;
+    }
+}
+
+template <class Matrix>
 bool
 mat_algo_test(Matrix& A, std::string test_name)
 {
@@ -110,28 +132,6 @@
   return success;
 }
 
-template <class Matrix>
-void
-set_diagonal_test(std::string test_name, Matrix& A, bool& success)
-{
-  if (A.is_unit()) {
-    std::cout << test_name.c_str() << " skipping set_diagonal" << std::endl;
-    return;
-  }
-  typedef typename mtl::matrix_traits<Matrix>::value_type T;
-  typedef typename mtl::matrix_traits<Matrix>::size_type Int;
-  // set_diagnal
-  Int i;
-  mtl::set_diagonal(A, T(1));
-  
-  for (i = 0; i < A.nrows() && i < A.ncols(); ++i)
-    if (A(i,i) != T(1)) {
-      std::cout << test_name.c_str() << " failed set_diagnal(A,a) *****" << std::endl;
-      success = false;
-      break;
-    }
-}
-
 template <class Mat>
 inline void
 fill_matrix(Mat& A, int /*sub*/, int /*super*/, mtl::rectangle_tag)
