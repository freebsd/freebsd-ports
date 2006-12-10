--- src/normalform/Filter.cc.orig	2004-07-30 12:58:12.000000000 +0200
+++ src/normalform/Filter.cc
@@ -54,7 +54,11 @@
 #include "config.h"
 #include "Filter.hh"
 #include "util/debug.hh"
+#if (__GNUC__ > 2)
 #include <ostream>
+#else
+#include <ostream.h>
+#endif
 
 using namespace std;
 
