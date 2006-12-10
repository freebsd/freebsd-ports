--- src/rpsl/rpsl/rangelist.cc.orig	2004-07-30 12:58:14.000000000 +0200
+++ src/rpsl/rpsl/rangelist.cc
@@ -53,7 +53,11 @@
 
 #include "config.h"
 #include "rangelist.hh"
+#if (__GNUC__ > 2)
 #include <ostream>
+#else
+#include <ostream.h>
+#endif
 
 using namespace std;
 
