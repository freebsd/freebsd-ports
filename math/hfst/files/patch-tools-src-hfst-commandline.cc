--- tools/src/hfst-commandline.cc.orig	2017-09-25 13:48:38.560155000 +0300
+++ tools/src/hfst-commandline.cc	2017-09-25 13:48:46.814581000 +0300
@@ -24,6 +24,8 @@
 #  define PACKAGE_BUGREPORT ""
 #endif
 
+#define _WITH_GETLINE
+
 #include <cassert>
 #include <climits>
 #include <cmath>
