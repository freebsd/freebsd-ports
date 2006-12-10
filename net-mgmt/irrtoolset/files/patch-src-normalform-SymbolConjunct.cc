--- src/normalform/SymbolConjunct.cc.orig	2004-07-30 12:58:13.000000000 +0200
+++ src/normalform/SymbolConjunct.cc
@@ -53,7 +53,11 @@
 
 #include "config.h"
 #include "SymbolConjunct.hh"
+#if (__GNUC__ > 2)
 #include <ostream>
+#else
+#include <ostream.h>
+#endif
 
 using namespace std;
 
