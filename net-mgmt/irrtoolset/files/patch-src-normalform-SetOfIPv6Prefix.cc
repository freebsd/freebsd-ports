--- src/normalform/SetOfIPv6Prefix.cc.orig	2004-07-30 12:58:13.000000000 +0200
+++ src/normalform/SetOfIPv6Prefix.cc
@@ -58,7 +58,11 @@
 #include "SetOfIPv6Prefix.hh"
 #include <cstdio>
 #include <cassert>
+#if (__GNUC__ > 2)
 #include <ostream>
+#else
+#include <ostream.h>
+#endif
 
 using namespace std;
 
