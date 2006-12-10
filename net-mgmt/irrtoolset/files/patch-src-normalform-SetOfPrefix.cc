--- src/normalform/SetOfPrefix.cc.orig	2004-07-30 12:58:13.000000000 +0200
+++ src/normalform/SetOfPrefix.cc
@@ -59,7 +59,11 @@
 #include <cstdio>
 #include <cassert>
 #include "rpsl/prefix.hh"
+#if (__GNUC__ > 2)
 #include <ostream>
+#else
+#include <ostream.h>
+#endif
 
 using namespace std;
 
