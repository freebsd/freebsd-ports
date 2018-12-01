--- library/src/linalg/lptab.cc.orig	2017-05-12 11:07:26 UTC
+++ library/src/linalg/lptab.cc
@@ -22,8 +22,9 @@
 
 #include "gambit/linalg/lptab.imp"
 
-using namespace Gambit;
-using namespace Gambit::linalg;
+namespace Gambit::linalg {
 
 template class LPTableau<double>;
 template class LPTableau<Rational>;
+
+}
