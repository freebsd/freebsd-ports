--- src/rpsl/rpsl/regexp.cc.orig	2004-07-30 12:58:14.000000000 +0200
+++ src/rpsl/rpsl/regexp.cc
@@ -56,7 +56,11 @@
 #include "regexp.hh"
 #include <cstring>
 #include "symbols.hh"
+#if (__GNUC__ > 2)
 #include <ostream>
+#else
+#include <ostream.h>
+#endif
 
 using namespace std;
 
