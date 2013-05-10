--- src/DLD-FUNCTIONS/__glpk__.cc.orig	2012-01-03 15:48:37.000000000 -0500
+++ src/DLD-FUNCTIONS/__glpk__.cc	2013-05-07 09:25:34.000000000 -0400
@@ -45,6 +45,7 @@
 #include <glpk/glpk.h>
 #else
 #include <glpk.h>
+#include <glplpx.h>
 #endif
 
 #if 0
