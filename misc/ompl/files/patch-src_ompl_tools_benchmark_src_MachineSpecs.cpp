--- src/ompl/tools/benchmark/src/MachineSpecs.cpp.orig	2018-08-04 18:25:01 UTC
+++ src/ompl/tools/benchmark/src/MachineSpecs.cpp
@@ -37,6 +37,7 @@
 #include "ompl/tools/benchmark/MachineSpecs.h"
 #include "ompl/util/Console.h"
 #include <sstream>
+#include <unistd.h>
 
 /// @cond IGNORE
 
