- Remove a non-existent directory from search.

--- lib/solver_config.cpp.orig	2022-02-17 23:53:35 UTC
+++ lib/solver_config.cpp
@@ -637,6 +637,7 @@ SolverConfigs::SolverConfigs(std::ostream& log) {
       FileUtils::directory_exists("/usr/local/share")) {
     _solverPath.emplace_back("/usr/local/share/minizinc/solvers");
   }
+#  if !defined(__FreeBSD__)
   if (_mznlibDir != "/usr/share/minizinc" && FileUtils::directory_exists("/usr/share")) {
     _solverPath.emplace_back("/usr/share/minizinc/solvers");
   }
@@ -648,6 +649,7 @@ SolverConfigs::SolverConfigs(std::ostream& log) {
       FileUtils::directory_exists("/opt/homebrew/share")) {
     _solverPath.emplace_back("/opt/homebrew/share/minizinc/solvers");
   }
+#endif
 #endif
 }
 
