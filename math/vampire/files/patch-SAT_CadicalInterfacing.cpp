-- Use the standard tracer.hpp include path so an external cadical package can be used.
-- The original hard-coded submodule path prevents using an installed cadical library.

--- SAT/CadicalInterfacing.cpp.orig	2026-11-06 16:15:28 UTC
+++ SAT/CadicalInterfacing.cpp
@@ -12,7 +12,7 @@
  * Implements class CadicalInterfacing
  */
 
-#include "cadical/src/tracer.hpp"
+#include <tracer.hpp>
 
 #include "CadicalInterfacing.hpp"
 #include "SATInference.hpp"
