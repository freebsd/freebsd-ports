-- Fix non-OpenMP serial build: use the actual log_ member instead of the
-- unrelated std::log function in the #else branch.

--- src/unitary.cpp.orig	2026-09-30 19:15:25 UTC
+++ src/unitary.cpp
@@ -110,7 +110,7 @@ void UnitaryOptimizer::open_log(const std::string & fn
 #ifdef _OPENMP
     fprintf(log_,"ERKALE - Localization from Hel, OpenMP version, running on %i cores.\n",omp_get_max_threads());
 #else
-    fprintf(log,"ERKALE - Localization from Hel, serial version.\n");
+    fprintf(log_,"ERKALE - Localization from Hel, serial version.\n");
 #endif
     fprint_copyright(log_);
     fprint_license(log_);
