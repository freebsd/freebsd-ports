--- library/src/linalg/lemketab.cc.orig	2018-12-01 17:13:48 UTC
+++ library/src/linalg/lemketab.cc
@@ -22,7 +22,9 @@
 
 #include "gambit/linalg/lemketab.imp"
 
-using namespace Gambit::linalg;
+namespace Gambit::linalg {
 
 template class LemkeTableau<double>;
 template class LemkeTableau<Gambit::Rational>;
+
+}
