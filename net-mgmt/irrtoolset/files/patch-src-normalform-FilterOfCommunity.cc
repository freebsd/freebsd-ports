--- src/normalform/FilterOfCommunity.cc.orig	2004-07-30 12:58:12.000000000 +0200
+++ src/normalform/FilterOfCommunity.cc
@@ -55,7 +55,11 @@
 #include "config.h"
 #include "FilterOfCommunity.hh"
 #include "util/debug.hh"
+#if (__GNUC__ > 2)
 #include <ostream>
+#else
+#include <ostream.h>
+#endif
 
 using namespace std;
 
