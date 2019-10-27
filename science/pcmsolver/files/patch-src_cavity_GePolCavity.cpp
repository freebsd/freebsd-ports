--- src/cavity/GePolCavity.cpp.orig	2019-10-24 12:25:02 UTC
+++ src/cavity/GePolCavity.cpp
@@ -21,6 +21,7 @@
  * PCMSolver API, see: <http://pcmsolver.readthedocs.io/>
  */
 
+#include <sys/types.h>
 #include "GePolCavity.hpp"
 
 #include <algorithm>
@@ -32,7 +33,6 @@
 #include <string>
 #include <vector>
 
-#include <sys/types.h>
 #include <unistd.h>
 
 #include "Config.hpp"
