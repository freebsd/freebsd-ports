- Remove a non-existent directory from search.

--- lib/solver_config.cpp.orig	2026-08-30 23:54:04 UTC
+++ lib/solver_config.cpp
@@ -679,6 +679,7 @@ SolverConfigs::SolverConfigs(std::ostream& log) {
       FileUtils::directory_exists("/usr/local/share")) {
     _solverPath.emplace_back("/usr/local/share/minizinc/solvers");
   }
+#  if !defined(__FreeBSD__)
   if (_mznlibDir != "/usr/share/minizinc" && FileUtils::directory_exists("/usr/share")) {
     _solverPath.emplace_back("/usr/share/minizinc/solvers");
   }
@@ -690,6 +691,7 @@ SolverConfigs::SolverConfigs(std::ostream& log) {
       FileUtils::directory_exists("/opt/homebrew/share")) {
     _solverPath.emplace_back("/opt/homebrew/share/minizinc/solvers");
   }
+#endif
 #endif
 
   // Add share/minizinc/solvers next to current exe to solver search paths as for some builtin
