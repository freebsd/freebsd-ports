--- src/rpsl/rpsl/rpsl_policy.cc.orig	2004-07-30 12:58:15.000000000 +0200
+++ src/rpsl/rpsl/rpsl_policy.cc
@@ -55,7 +55,11 @@
 #include <cstdio>
 #include "rpsl_policy.hh"
 #include "rpsl_attr.hh"
+#if (__GNUC__ > 2)
 #include <ostream>
+#else
+#include <ostream.h>
+#endif
 
 using namespace std;
 
