--- mfront/src/NewtonRaphsonSolvers.cxx.orig	2019-04-04 06:48:40 UTC
+++ mfront/src/NewtonRaphsonSolvers.cxx
@@ -11,6 +11,7 @@
  * project under specific licensing conditions.
  */
 
+#include <ostream>
 #include "TFEL/Raise.hxx"
 #include "MFront/MFrontDebugMode.hxx"
 #include "MFront/BehaviourDescription.hxx"
