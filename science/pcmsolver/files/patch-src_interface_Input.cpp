--- src/interface/Input.cpp.orig	2019-10-24 12:34:49 UTC
+++ src/interface/Input.cpp
@@ -21,6 +21,7 @@
  * PCMSolver API, see: <http://pcmsolver.readthedocs.io/>
  */
 
+#include <sys/types.h>
 #include "Input.hpp"
 
 #include <algorithm>
