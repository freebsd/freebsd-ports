--- library/src/matrix.cc.orig	2018-12-01 16:51:25 UTC
+++ library/src/matrix.cc
@@ -25,11 +25,15 @@
 
 using namespace Gambit;
 
+namespace Gambit {
+
 template class Matrix<double>;
 template class Matrix<Rational>;
 template class Matrix<Integer>;
 template class Matrix<int>;
 
+}
+
 template Vector<double> Gambit::operator*(const Vector<double> &,
 					  const Matrix<double> &);
 template Vector<Rational> Gambit::operator*(const Vector<Rational> &,
