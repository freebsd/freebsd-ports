- Remove a non-existent directory from search.

--- lib/solver_config.cpp.orig	2021-05-02 20:37:56 UTC
+++ lib/solver_config.cpp
@@ -662,9 +662,11 @@ SolverConfigs::SolverConfigs(std::ostream& log) {
       FileUtils::directory_exists("/usr/local/share")) {
     _solverPath.emplace_back("/usr/local/share/minizinc/solvers");
   }
+#  if !defined(__FreeBSD__)
   if (_mznlibDir != "/usr/share/minizinc" && FileUtils::directory_exists("/usr/share")) {
     _solverPath.emplace_back("/usr/share/minizinc/solvers");
   }
+#  endif
 #endif
 }
 
