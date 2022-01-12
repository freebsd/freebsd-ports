- backport of fix: https://git.dynare.org/Dynare/preprocessor/-/commit/8c528f4f9a15baf73c014e1c3e55bc13583ca09d

--- preprocessor/src/EquationTags.cc.orig	2022-01-10 23:30:53 UTC
+++ preprocessor/src/EquationTags.cc
@@ -20,6 +20,7 @@
 #include "EquationTags.hh"
 
 #include <regex>
+#include <ostream>
 
 set<int>
 EquationTags::getEqnsByKey(const string &key) const
