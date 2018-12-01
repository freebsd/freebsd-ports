--- library/src/linalg/lhtab.cc.orig	2018-12-01 17:29:54 UTC
+++ library/src/linalg/lhtab.cc
@@ -22,12 +22,11 @@
 
 #include "gambit/linalg/lhtab.imp"
 
-using namespace Gambit;
-using namespace Gambit::linalg;
+namespace Gambit::linalg {
 
 template class LHTableau<double>;
 template class LHTableau<Rational>;
 
-
+}
 
 
