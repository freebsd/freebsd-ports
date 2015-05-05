--- cryptominisat4/bva.cpp.orig	2014-07-14 22:45:03 UTC
+++ cryptominisat4/bva.cpp
@@ -25,6 +25,7 @@
 #include "clausecleaner.h"
 #include "subsumeimplicit.h"
 #include "sqlstats.h"
+#include <cmath>
 #include <functional>
 
 using namespace CMSat;
