--- aux0/aux0print.cc.orig	Sun Jul 11 23:08:11 2004
+++ aux0/aux0print.cc	Wed Oct  6 22:31:25 2004
@@ -1,6 +1,8 @@
 
 #include "fxtio.h"
 
+#include <cmath>
+
 
 void
 print_fixed(const char *bla, double v, long nd, bool sq)
