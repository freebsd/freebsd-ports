-- Use the standard cadical.hpp include path so an external cadical package can be used.
-- The original hard-coded submodule path prevents using an installed cadical library.
--- SAT/CadicalInterfacing.hpp.orig	2026-11-06 16:15:28 UTC
+++ SAT/CadicalInterfacing.hpp
@@ -20,7 +20,7 @@
 
 #include "MinisatInterfacing.hpp"
 
-#include "cadical/src/cadical.hpp"
+#include <cadical.hpp>
 
 namespace SAT{
 
