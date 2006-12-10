--- src/rpsl/rpsl/schema.cc.orig	2004-07-30 12:58:15.000000000 +0200
+++ src/rpsl/rpsl/schema.cc
@@ -53,7 +53,11 @@
 
 #include "config.h"
 
+#if (__GNUC__ > 2)
 #include <ostream>
+#else
+#include <ostream.h>
+#endif
 #include <cstring>
 #include <cstdio>
 #include "gnu/std.h"
