--- libinterp/dldfcn/__glpk__.cc.orig	2014-01-20 06:29:02.000000000 -0700
+++ libinterp/dldfcn/__glpk__.cc	2014-01-20 06:32:50.000000000 -0700
@@ -46,6 +46,7 @@
 #include <glpk/glpk.h>
 #else
 #include <glpk.h>
+#include <glplpx.h>
 #endif
 }
 
