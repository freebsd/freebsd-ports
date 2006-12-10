--- src/normalform/FilterOfASPath.cc.orig	2004-07-30 12:58:12.000000000 +0200
+++ src/normalform/FilterOfASPath.cc
@@ -55,7 +55,11 @@
 #include "util/debug.hh"
 #include "FilterOfASPath.hh"
 #include <cstdio>
+#if (__GNUC__ > 2)
 #include <ostream>
+#else
+#include <ostream.h>
+#endif
 
 using namespace std;
 
