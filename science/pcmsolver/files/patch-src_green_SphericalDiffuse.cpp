--- src/green/SphericalDiffuse.cpp.orig	2019-10-24 12:30:56 UTC
+++ src/green/SphericalDiffuse.cpp
@@ -21,6 +21,7 @@
  * PCMSolver API, see: <http://pcmsolver.readthedocs.io/>
  */
 
+#include <sys/types.h>
 #include "SphericalDiffuse.hpp"
 
 #include <iosfwd>
