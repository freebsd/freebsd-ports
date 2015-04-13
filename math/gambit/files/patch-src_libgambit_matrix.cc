--- src/libgambit/matrix.cc.orig	2014-06-06 16:33:54.000000000 +0400
+++ src/libgambit/matrix.cc	2015-04-13 21:39:08.802909000 +0300
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
