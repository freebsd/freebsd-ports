--- library/src/linalg/ludecomp.cc.orig	2017-05-12 11:07:26 UTC
+++ library/src/linalg/ludecomp.cc
@@ -22,11 +22,12 @@
 
 #include "gambit/linalg/ludecomp.imp"
 
-using namespace Gambit;
-using namespace Gambit::linalg;
+namespace Gambit::linalg {
 
 template class EtaMatrix<double>;
 template class LUdecomp<double>;
 
 template class EtaMatrix<Rational>;
 template class LUdecomp<Rational>;
+
+}
