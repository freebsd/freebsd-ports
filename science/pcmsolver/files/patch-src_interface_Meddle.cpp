--- src/interface/Meddle.cpp.orig	2019-10-24 12:36:20 UTC
+++ src/interface/Meddle.cpp
@@ -21,6 +21,7 @@
  * PCMSolver API, see: <http://pcmsolver.readthedocs.io/>
  */
 
+#include <sys/types.h>
 #include "Meddle.hpp"
 #include "PCMInput.h"
 #include "pcmsolver.h"
