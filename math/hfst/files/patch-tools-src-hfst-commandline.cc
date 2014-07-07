--- tools/src/hfst-commandline.cc.orig	2014-07-04 18:13:51.000000000 +0400
+++ tools/src/hfst-commandline.cc	2014-07-04 18:14:35.000000000 +0400
@@ -21,6 +21,7 @@
 #  include <config.h>
 #endif
 
+#define _WITH_GETLINE
 #include <cassert>
 #include <climits>
 #include <cmath>
