--- library/src/linalg/btableau.cc.orig	2018-12-01 17:24:33 UTC
+++ library/src/linalg/btableau.cc
@@ -24,8 +24,7 @@
 #include "gambit/matrix.imp"
 #include "gambit/linalg/btableau.imp"
 
-using namespace Gambit;
-using namespace Gambit::linalg;
+namespace Gambit::linalg {
 
 template class BaseTableau<double>;
 template class BaseTableau<Rational>;
@@ -33,4 +32,4 @@ template class BaseTableau<Rational>;
 template class TableauInterface<double>;
 template class TableauInterface<Rational>;
 
-
+}
